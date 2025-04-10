package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	if len(os.Args) != 3 {
		fmt.Println("Usage: go run converter.go <input.html> <output.c>")
		return
	}

	inputFileName := os.Args[1]
	outputFileName := os.Args[2]

	inputFile, err := os.Open(inputFileName)
	if err != nil {
		fmt.Println("Error opening input file:", err)
		return
	}
	defer inputFile.Close()

	outputFile, err := os.Create(outputFileName)
	if err != nil {
		fmt.Println("Error creating output file:", err)
		return
	}
	defer outputFile.Close()

	scanner := bufio.NewScanner(inputFile)
	for scanner.Scan() {
		line := scanner.Text()
		escapedLine := strings.ReplaceAll(line, "\\", "\\\\")
		escapedLine = strings.ReplaceAll(escapedLine, "\"", "\\\"")
		cString := fmt.Sprintf("\"%s\\r\\n\"", escapedLine)

		_, err = outputFile.WriteString(cString + "\n")
		if err != nil {
			fmt.Println("Error writing to output file:", err)
			return
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading input file:", err)
	}

	fmt.Println("Conversion complete.")
}
