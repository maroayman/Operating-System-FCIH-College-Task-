#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	int ch,ch1;
	char file[20],perm[10],cmd[80],name[20],fn1[15],fn2[15];
	do {
	printf("1-List files and directories\n2-Change permissions of file\n3-Make/delete file/directory\n4-Create symbolic link files:\n5-Exit Program:\n\n");
	scanf("%d",&ch);
    switch(ch) {
	//List files and directories
    case 1:
    		system("ls -l");
            break;
	//Change permission of file
    case 2:
    puts("Enter the permissions of file you want to change:");
	scanf("%s",perm);
	if(!(strcmp(perm,"+r"))||!(strcmp(perm,"+w"))||!(strcmp(perm,"+rw"))||!(strcmp(perm,"-r"))||!(strcmp(perm,"-w"))||!(strcmp(perm,"-rw"))){
        puts("Enter filename");
        scanf("%s",file);
        sprintf(cmd,"chmod %s %s",perm,file);
        if(!system(cmd))
        puts("Changed permissions successfully");
        else
        puts("Error in filename");
        }
        else puts("File permissions are wrong");
        break;
    case 3:
        puts("1-Make File\n2-Make Directory\n3-Delete File/Directory\n:");
        scanf("%d",&ch1);
        //----------/ Option 1
        if(ch1==1){
            puts("Enter file-name:\n");
            scanf("%s",name);
            sprintf(cmd,"touch %s",name);
            if(access(name,F_OK) != 0)
            {system(cmd);puts("File created successfully");}
            else {puts("This file is exist, try another filename.");}
                }

        //----------/ Option 2
        if(ch1==2){
            puts("Enter Directory-name:\n");
            scanf("%s",name);
            sprintf(cmd,"mkdir %s",name);
            //system(cd2);
            if(!system(cmd)){
                puts("Directory created successfully");}
                else{puts("Directory is not created successfully");}}

        //----------/ Option 3
            if(ch1==3){
            puts("Enter File/Directory-name:\n");
            scanf("%s",name);
            sprintf(cmd,"rm -rf -i %s",name);
            //system(cd3);
            if(!system(cmd))
                puts("File is removed successfully");
            else
                puts("Filename is wrong");
            }
            break;

            //----------/ Option 4

            case 4:
                printf("Enter the filename:\n");
                scanf("%s",fn1);
                printf("Enter s-link name:\n");
                scanf("%s",fn2);
                sprintf(cmd,"ln -s %s %s",fn1,fn2);
                if(lstat(fn2)){
                if(!system(cmd))
                puts("Shortcut is created successfully");
                }
                break;


            case 5:
                exit(0);
                return 0;

            default:
                puts("Wrong choice");
           }}
        while(ch!=5);
	return 0;
}
