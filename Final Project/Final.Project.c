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
void processor(FILE *f){                                                       //Functions:
    for(int i=0 ; i<30 ; i++){
        buffer[i] = toupper(buffer[i]);
    }
    for(int i=0 ; i<30 ; i++){
        funcname[i] = toupper(funcname[i]);
    }
    if(strcmp(funcname,"ADD") == 0){                                           //ADD
        int S_rd,S_rs,S_rt; 
        sscanf(buffer,"ADD S%d, S%d, S%d",&S_rd,&S_rs,&S_rt);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] + S[S_rt] ;
            situation(S[S_rd]);
            overflow(S[S_rs],S[S_rt],S[S_rd]);
        }
    }
    else if(strcmp(funcname,"SUB") == 0){                                      //SUB
        int S_rd,S_rs,S_rt;
        sscanf(buffer,"SUB S%d, S%d, S%d",&S_rd,&S_rs,&S_rt);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] - S[S_rt] ;
            situation(S[S_rd]);
            overflow(S[S_rs],S[S_rt]*(-1),S[S_rd]);
        }
    }
    else if(strcmp(funcname,"AND") == 0){                                      //AND
        int S_rd,S_rs,S_rt;
        sscanf(buffer,"AND S%d, S%d, S%d",&S_rd,&S_rs,&S_rt);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] & S[S_rt] ;
            situation(S[S_rd]);
        }
    }
    else if(strcmp(funcname,"XOR") == 0){                                      //XOR
        int S_rd,S_rs,S_rt;
        sscanf(buffer,"XOR S%d, S%d, S%d",&S_rd,&S_rs,&S_rt);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] ^ S[S_rt] ;
            situation(S[S_rd]);
        }
    }
    else if(strcmp(funcname,"OR") == 0){                                       //OR
        int S_rd,S_rs,S_rt;
        sscanf(buffer,"OR S%d, S%d, S%d",&S_rd,&S_rs,&S_rt);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] | S[S_rt] ;
            situation(S[S_rd]);
        }
    }
    else if(strcmp(funcname,"ADDI") == 0){                                     //ADDI
        int S_rd,S_rs,Imm;
        sscanf(buffer,"ADDI S%d, S%d, %d",&S_rd,&S_rs,&Imm);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Input-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] + Imm ;
            situation(S[S_rd]);
            overflow(S[S_rs],Imm,S[S_rd]);
        }
    }
    else if(strcmp(funcname,"SUBI") == 0){                                     //SUBI
        int S_rd,S_rs,Imm;
        sscanf(buffer,"SUBI S%d, S%d, %d",&S_rd,&S_rs,&Imm);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Input-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] - Imm ;
            situation(S[S_rd]);
            overflow(S[S_rs],Imm*(-1),S[S_rd]);
        }
    }
    else if(strcmp(funcname,"ANDI") == 0){                                     //ANDI
        int S_rd,S_rs,Imm;
        sscanf(buffer,"ANDI S%d, S%d, %d",&S_rd,&S_rs,&Imm);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Input-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] & Imm ;
            situation(S[S_rd]);
        }
    }
    else if(strcmp(funcname,"XORI") == 0){                                     //XORI
        int S_rd,S_rs,Imm;
        sscanf(buffer,"XORI S%d, S%d, %d",&S_rd,&S_rs,&Imm);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Input-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] ^ Imm ;
            situation(S[S_rd]);
        }
    }
    else if(strcmp(funcname,"ORI") == 0){                                      //ORI
        int S_rd,S_rs,Imm;
        sscanf(buffer,"ORI S%d, S%d, %d",&S_rd,&S_rs,&Imm);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"input-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] | Imm ;
            situation(S[S_rd]);
        }
    }
    else if(strcmp(funcname,"MOV") == 0){                                      //MOV
        if(buffer[8]=='S' || buffer[9]=='S'){
            int S_rt,S_rs;
            sscanf(buffer,"MOV S%d, S%d",&S_rt,&S_rs);
            if(S_rt<0 || S_rt>31){
                fprintf(stderr,"First-register is out of range!\n");
            }
            else if(S_rs<0 || S_rs>31){
                fprintf(stderr,"Second-register is out of range!\n");
            }
            else{
                S[S_rt] = S[S_rs];
            }
        }
        else{    
            int S_rt,Imm;
            sscanf(buffer,"MOV S%d, %d",&S_rt,&Imm);
            if(S_rt<0 || S_rt>31){
                fprintf(stderr,"Input-register is out of range!\n");
            }
            else{
                S[S_rt] = Imm;
            }
        }   
    }
    else if(strcmp(funcname,"SWP") == 0){                                      //SWP
        int S_rt,S_rs;
        sscanf(buffer,"SWP S%d, S%d",&S_rt,&S_rs);
        if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else{
            int temp = S[S_rt] ;
            S[S_rt] = S[S_rs];
            S[S_rs] = temp;
        }
    }
    else if(strcmp(funcname,"DUMP_REGS") == 0){                                //DUMP_REGS
        printf("Registers: \n");
        for(int i=0 ; i<32 ; i++){
            printf("%-2d: %-10d\n",i,S[i]);
        }
        printf("Situation Register: \n");
        for(int i=7 ; i>-1 ; i--){
            printf("%d",vini[i]);
        }
        printf("\n");
    }
    else if(strcmp(funcname,"DUMP_REGS_F") == 0){                              //DUMP_REGS_F
        FILE *file ;
        file = fopen("regs.txt","w+");
        fprintf(file,"Registers: \n");
        for(int i=0 ; i<32 ; i++){
            fprintf(file,"%d: %d\n",i,S[i]);
        }
        fprintf(file,"Situation Register: \n");
        for(int i=7 ; i>-1 ; i--){
            fprintf(file,"%d",vini[i]);
        }
    }
    else if(strcmp(funcname,"INPUT") == 0){                                    //INPUT
        printf("Enter number: ");
        scanf("%d",&S[0]);
        situation(S[0]);
    }
    else if(strcmp(funcname,"OUTPUT") == 0){                                   //OUTPUT
        printf("S0 value is %d\n",S[0]);
    }
    else if(strcmp(funcname,"JMP") == 0){                                      //JMP
        int temp;
        sscanf(buffer,"JMP %d",&temp);
        if(temp>current_line){
            line = temp ;
            current_line = 0 ;
            rewind(f);
        }
        else if(temp==current_line){
            if(jmploop!=1){
                fprintf(stderr,"Caution! This action may cause endless loop!\n");
                fprintf(stderr,"Do you want to continue or skip?(c/s) ");
                char ask[0];
                scanf("%s",&ask);
                if( ask[0] == 's' ){
                    line = 0;
                }
                else{
                    jmploop++;
                    line = temp ;
                    current_line = 1 ;
                    rewind(f);
                }   
            }
            else{
                line = temp ;
                current_line = 1 ;
                rewind(f);
            }
        }
        else{
            if(jmploop!=1){
                fprintf(stderr,"Caution! This action may cause endless loop!\n");
                fprintf(stderr,"Do you want to continue or skip?(c/s) ");
                char ask[0];
                scanf("%s",&ask);
                if( ask[0] == 's' ){
                    line = 0;
                }
                else{  
                    jmploop++;
                    line = temp ;
                    current_line = 1 ;
                    rewind(f);
                }
            }
            else{
                line = temp ;
                current_line = 1 ;
                rewind(f);
            }
        }
    }
    else if(strcmp(funcname,"EXIT") == 0){                                       //EXIT
        ext();
    }
    else if(strcmp(funcname,"MLT") == 0){                                        //MLT
        int S_rd,S_rs,S_rt; 
        sscanf(buffer,"MLT S%d, S%d, S%d",&S_rd,&S_rs,&S_rt);
        if(S_rd<0 || S_rd>31){
            fprintf(stderr,"Destination-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else{
            S[S_rd] = S[S_rs] * S[S_rt] ;
            situation(S[S_rd]);
            overflow(S[S_rs],S[S_rt],S[S_rd]);
        }

    }
    else if(strcmp(funcname,"DIV") == 0){                                        //DIV
        int S_rt,S_rs;
        int temp;
        sscanf(buffer,"DIV S%d, S%d",&S_rt,&S_rs);
        temp = S[S_rt] ;
        if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else{
            S[S_rt] = S[S_rt] / S[S_rs] ;
            S[S_rs] = temp % S[S_rs] ;
            printf("%d %d %d\n",S[S_rt],S[S_rs],temp);
            situation(S[S_rt]);
        }
    }
    else if(strcmp(funcname,"SKIE") == 0 ){                                      //SKIE
        int S_rt,S_rs;
        sscanf(buffer,"SKIE S%d, S%d",&S_rt,&S_rs);
        if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){
            fprintf(stderr,"Second-register is out of range!\n");
            
        }
        else{
            if(S[S_rt] == S[S_rs]){
                line = current_line + 2 ;
            }
        }
    }
    else if(strcmp(funcname,"MULL") == 0 ){                                      //MULL
        int S_rt,S_rs;
        int result;
        sscanf(buffer,"MULL S%d, S%d",&S_rt,&S_rs);
        if(S_rt<0 || S_rt>31){
            fprintf(stderr,"First-register is out of range!\n");
        }
        else if(S_rs<0 || S_rs>31){                                             
            fprintf(stderr,"Second-register is out of range!\n");
        }
        else{
            int result = S[S_rt] * S[S_rs] ;
            situation(result);
            S[S_rs] = result & 15 ;
            int count1 = 0, count0 = 0 ;
            int temp = result ;
            while(result>0){
                if((result & 1) == 1){
                    count1++;
                }
                result = result >> 1 ;
            }
            int num_1 = count1 ; 
            result = temp ;
            while(count1>0){
                if((result & 1) == 0){
                    count0++;
                }
                else{
                    count1--;
                }
                result = result >> 1 ;
            }    
            int num_0 = count0 ;
            if(num_0 + num_1 > 4 ){
                result = temp ;  
                S[S_rt] = result >> (num_0 + num_1 - 4) ;
            }
            else{
                S[S_rt] = S[S_rs] ;
            }
        }
    }
    else if(strcmp(funcname,"INFO") == 0){                                       //INFO
        char h[200];                                   
        FILE *inf;
        inf = fopen("info.txt" ,"r");
        while(fscanf(inf,"%[^\n]\n",h) != EOF ){
            puts(h);
        }
        fclose(inf);
    }
    else if(strcmp(funcname,"PUSH") == 0){                                       //PUSH
        int S_rs;
        sscanf(buffer,"PUSH S%d",&S_rs);
        ram[current_ram] = S[S_rs] ;
        current_ram++;
    }
    else if(strcmp(funcname,"POP") == 0){                                        //POP
        int S_rt;
        sscanf(buffer,"POP S%d",&S_rt);
        if(current_ram-1 >= 0){
            S[S_rt] = ram[current_ram-1] ; 
            current_ram--;
        }
        else{
            fprintf(stderr,"Ram is empty!\n");
        }
    }
    else if(strcmp(funcname,"SPY") == 0){                                        //SPY
        for(int i=0 ; i<10 ; i++){
            ram[i]=0;
        }
        for(int i=0 ; i<32 ; i++){
            S[i] = 0 ;
        }
        fprintf(stderr,"All files have been deleted successfully!");
    }
    else{
        fprintf(stderr,"Input function correctly!!\n");
    }
}
void situation(int result){
    if(result==0){                                              //Zero flag 
        vini[1] = 1;
    }
    else{
        vini[1]=0;
    }
    if(result<0){                                               //Sign flag
        vini[2]=1;
    }
    else{
        vini[2]=0;
    }
    int count=0;                                                //Parity flag
    while(result>0){
        if((result & 1) == 1){
            count++;
        }
        result = result >> 1 ;
    }
    if(count%2 == 0){
        vini[0]=0;
    }
    else{
        vini[0]=1;
    }
}