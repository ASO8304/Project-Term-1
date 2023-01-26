void overflow(int first,int second,int result){
    if(first>0 && second>0){
        if(result>0){
            vini[5]=0;
        }
        else{
            vini[5]=1;
        }
    }
    else if(first<0 && second<0){
        if(result<0){
            vini[5]=0;
        }
        else{
            vini[5]=1;
        }
    }
    else if((first*second)<0){
        vini[5]=0;
    }
}
void ext(){
    char ask[1];
    fprintf(stderr,"Are you sure about exiting?(y/n) ");
    scanf("%s", ask);
    if(strcmp(ask,"y") == 0){
        status = 0;
        fprintf(stderr,"Program is finished successfully! :)\n");
    }
}