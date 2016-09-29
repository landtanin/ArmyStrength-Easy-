//
//  main.cpp
//  ArmyStrength(Easy)
//
//  Created by landtanin on 9/29/2559 BE.
//  Copyright © 2559 landtanin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    using namespace std;
    
    int testNumber;
    int army[2];
    int **monsters = new int*[2];
    int monsPos[2];
    int lowest;
    
    cin>>testNumber;
    
    string *result = new string[testNumber];
    
    for(int i=0; i<testNumber; i++){
        
        cout<<endl<<endl;
        
        army[0] = 0;
        army[1] = 0;
        
        cin>>army[0]>>army[1];
        
        // allocate array column
        for(int x=0; x< 2;++x){
            monsters[x] = new int[army[x]];
        }
    
        
//        cout<<sizeof(monsters[0])/sizeof(int)<<"!!"<<sizeof(monsters[1])/sizeof(int);
        
        
        // take monsters' strengths
        
        for(int j=0; j<2; j++){
        
            for(int k=0; k<army[j]; k++){
                
                cin>>monsters[j][k];
                
            }
            
//            cout<<endl;
        }
        
        cout<<"finish take strength"<<monsters[0][0]<<endl;
        
        
        
        
        while((monsters[0][0]>0)&&(monsters[1][0]>0)){
            
            cout<<"enter while"<<monsters[0][0]<<monsters[1][0]<<endl;
            
            lowest=10000;
            
//            int deductNumber = 0;

            
            monsPos[0] = 0;
            monsPos[1] = 0;
        
            for(int i = 0;i<(army[0]+army[1]);i++){
            
//                deductNumber = army[0]-i;
                cout<<"i="<<i<<endl;
                
                if(i<army[0]){
                
                    if(monsters[0][i]==lowest){
                        
                        monsPos[0] = 1;
                        monsPos[1] = i;
                        cout<<"first="<<lowest<<endl;
                    }
                    
                    else if(monsters[0][i]<lowest){
                        
                        lowest=monsters[0][i];
                        monsPos[0] = 0;
                        monsPos[1] = i;
                        cout<<"second="<<lowest<<endl;
                    }
                
                }else if(i>=army[0]){
                
                    if(monsters[1][i-(army[0])]<lowest){
                    
                        lowest=monsters[1][i];
                        monsPos[0] = 1;
                        monsPos[1] = i-(army[0]);
                        cout<<"third="<<lowest<<endl;
                    
                    }else if(monsters[1][i-army[0]]==lowest){
                        
                        monsPos[0] = 1;
                        monsPos[1] = i-(army[0]);
                        cout<<"four="<<lowest<<endl;
                    }
//                    else if(monsters[1][i-(army[0]-i)]==lowest){
//                        
//                        monsPos[0] = 1;
//                        monsPos[1] = i-(army[0]-i);
//                    }

                    
                }
                
               
            }
            
            // eliminate lowest
            for(int k = monsPos[1];k<army[monsPos[0]];k++){
                
                cout<<"eleminate"<<monsPos[0]<<monsPos[1]<<lowest<<endl;
                monsters[monsPos[0]][k] = monsters[monsPos[0]][k+1];
                //                cout<<monsters[0][2]<<endl;
            }
            
         
        }
        
        if(monsters[0][0]>monsters[1][0]){
            result[i] = "Godzilla";
        }
        
        else if(monsters[0][0]<monsters[1][0]){
            result[i] = "MechaGodzilla";
        }
        cout<<"battle done"<<result[i]<<monsters[0][0]<<monsters[1][0]<<endl;
        
        // clear data
        for(int j = 0;j<2;j++){
            
            for(int i = 0;i<army[j];i++){
                monsters[j][i] = 0;
            }
            
        }
        
        
    }
    
    //---------------------
    
    for(int i = 0;i<testNumber;i++){
    
        cout<<result[i]<<monsters[0][0]<<monsters[1][0]<<endl;
    
    }
    
    
    return 0;
}
