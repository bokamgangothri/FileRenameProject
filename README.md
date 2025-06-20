**Rename multiple files using C++**
Now say given n images in a folder having random names. For example, consider the image below:
![1-103](https://github.com/user-attachments/assets/fcdb553b-e83f-4068-9c8d-37b765235cc1)

Now the requirement is to rename them in ordered fashion like hostel1, hostel2, ...and so on. Doing this manually would be a tedious task but this target can be achieved using the rename() and listdir() methods in the os module.

With this project code will do the job for us. It traverses through the lists of all the images in xyz folder, defines the destination (dst) and source (src) addresses, and renames using rename module. 

The accepted format for destination (dst) and source (src) addresses to be given as arguments in rename(src,dst) is "folder_name/file_name".

The output of this code will look something like this - 
 ![image](https://github.com/user-attachments/assets/12d45a41-48b3-46c6-9e80-57567db690c2)


