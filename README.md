# ICT283 Data Structures and Abstractions 
Below is week 1 content of ICT283.

Todo - Create a list 

## Download StarUML
The installer is in the attached zip file inside OneDrive. 

## Download Doxygen
Make sure to install [Graphviz](https://markdownlivepreview.com/) before attempting to download [Doxygen](https://www.doxygen.nl/download.html#google_vignette).

Run Doxywizard whenever external documentation is required. 

1. Specify the working directory from which doxygen will run.
2. Fill all the relevant information under _Wizard > Topics > Projects_
3. Under _Wizard > Topics > Mode_, make sure: 
    1. "All Entities" is picked
    2. "Include cross-referenced source code in the output" is checked
    3. "Optimize for C++ output" is selected
4. Under _Wizard > Topics > Output_, make sure: 
    1. "HTML" is checked
    2. "with navigation panel" is selected
    3. "With search function" is checked
5. Under _Wizard > Topics > Diagrams_, make sure:
    1. "Use dot tool from the GraphViz package" is selected
    2. All of checkboxes for Dot graphs are checked
7. Under _Expert > Dot_, make sure:
    1. "Hide\_UNDOC\_RELATIONS" is unchecked
    2. "HAVE_DOT" is checked
    3. "UML_LOOK" is checked
    4. "TEMPLATE_RELATIONS" is checked
    5. "INCLUDE_PATH" is checked
    6. "INCLUDED_BY_GRAPH" is checked
    7. "CALL_GRAPH" is checked
    8. "CALLER_GRAPH" is checked
    9. "GRAPHICAL_HIERARCHY" is checked
    10. "DIRECTORY_GRAPH" is checked
    11. "DOT_PATH" contains the path of GraphViz bin folder
    12. Go to _File_ and save the configuration file. The configuration file can be copied to other lab and assignment. Make sure to change the source and destination folder.
8. Under _Run_, there should be a button called "Run Doxygen". Once it is run, we should be able to show HTML output.


## Download CodeBlocks
Use the latest version provided by the [official website](https://www.codeblocks.org/downloads/binaries/).

Codeblock will need two of the following flags to be enabled:
1. Have g++ follow the C\+\+11 ISO C++ language standard 
2. Have gcc follow the 2011 ISO C language standard
