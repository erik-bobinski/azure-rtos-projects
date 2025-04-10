/*
 * html_content.h
 *
 *  Created on: Apr 2, 2025
 *      Author: ebob
 */

#ifndef HTML_CONTENT_H_
#define HTML_CONTENT_H_

/* HTTP contents */
char test_contents[] =
        "<!DOCTYPE html>\r\n"
        "<html lang=\"en\">\r\n"
        "<head>\r\n"
        "    <meta charset=\"UTF-8\">\r\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n"
        "    <title>Document</title>\r\n"
        "</head>\r\n"
        "<body>\r\n"
        "    <h1>Test Page</h1>\r\n"
        "    <p id=\"displayVariable\"></p>\r\n"
        "    <button id=\"incrementButton\">Increment</button>\r\n"
        "    <script>\r\n"
        "        // Define a variable\r\n"
        "        let myVariable = 0;\r\n"
        "        \r\n"
        "        // Display the variable in the paragraph element\r\n"
        "        document.getElementById('displayVariable').textContent = myVariable;\r\n"
        "        \r\n"
        "        // Add click event listener to the button\r\n"
        "        document.getElementById('incrementButton').addEventListener('click', () => {\r\n"
        "            myVariable++;\r\n"
        "            document.getElementById('displayVariable').textContent = myVariable;\r\n"
        "        });\r\n"
        "    </script>\r\n"
        "</body>\r\n"
        "</html>\r\n";


#endif /* HTML_CONTENT_H_ */
