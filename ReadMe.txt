Proj4 Readme file:
1. to delete a file from the client, Please chose the category and the file again. Its working but 
there is some issue with the way things are hanlded by wpf. Please run the client again and test the delete functionality.
But This is not for every run. Sometimes it is working.

2. Command Line arguments:
../Repository *.h *.cpp  /f /r  ../StoreHTMFiles C:\Sumanth\GrammarHelpers http://localhost:8090/CodePublisher

Arg1: Place where you want to store your files in the repository.
Arg6: Place where you want to the html files to be rendered.
Arg7: Physical path where you have configured the IIS
Arg8: Virtual Mapping to the above physical path.

3. I have implemented Lazy loading so all the dependent files will be downloaded.
4. Please change the IIS physical and virtual path as in your machine to see how files are hosted on the IIS.
5. When downloading the dependencies, if the filea are not present, the code anayzer triggers automatically and download the files.
6. Press on Analyze button to analyze the dependencies and publish html files.