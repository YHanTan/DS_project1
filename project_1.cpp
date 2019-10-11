#include <iostream>
#include <string>
using namespace std;

// Pieces definition
int Pieces [19 /*kind */ ][4 /* ROW */ ][4 /* COL */] =
{
    // T1
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 0}
    },
    //T2
   {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0}
    },
    //T3
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 1, 0}
    },
    //T4
   {
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0}
    },

    //L1
   {
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 0, 0}
    },
    //L2
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 1, 0},
    {1, 0, 0, 0}
    },
    //L3
   {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
    },
    //L4
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 1, 0}
    },


  //J1
   {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0}
    },
    //J2
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 1, 0}
    },
    //J3
   {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
    },
    //J4
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 1, 0}
    },

    //S1
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {1, 1, 0, 0}
    },
    //S2
   {
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0}
    },
    //Z1
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0}
    },
    //Z2
   {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0}
    },

    //I1
   {
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
    },
    //I2
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 1, 1}
    },
    //O
   {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 0, 0}
    },

};


int main()
{
    int row, col;
    string type;
    int type_num;
    int drop_pos;

    cin >> row >> col;
    cin >> type >> drop_pos;
    int game[row+4][col+8]={0};
    for(int i=0; i<row+4; i++){
        for(int j=0; j<col+8; j++){
            game[i][j]=0;
        }
    }
    int col_first[col+8]={row+4};

    while(type!="End"){
        //cout << type << endl;
        int block_now[4][4] = {0};
        if(type=="T1"){
            type_num = 0;
        }
        else if(type=="T2"){
            type_num = 1;
        }
        else if(type=="T3"){
            type_num = 2;
        }
        else if(type=="T4"){
            type_num = 3;
        }
        else if(type=="L1"){
            type_num = 4;
        }
        else if(type=="L2"){
            type_num = 5;
        }
        else if(type=="L3"){
            type_num = 6;
        }
        else if(type=="L4"){
            type_num = 7;
        }
        else if(type=="J1"){
            type_num = 8;
        }
        else if(type=="J2"){
            type_num = 9;
        }
        else if(type=="J3"){
            type_num = 10;
        }
        else if(type=="J4"){
            type_num = 11;
        }
        else if(type=="S1"){
            type_num = 12;
        }
        else if(type=="S2"){
            type_num = 13;
        }
        else if(type=="Z1"){
            type_num = 14;
        }
        else if(type=="Z2"){
            type_num = 15;
        }
        else if(type=="I1"){
            type_num = 16;
        }
        else if(type=="I2"){
            type_num = 17;
        }
        else if(type=="O"){
            type_num = 18;
        }
        //cout << "2222";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                block_now[i][j] = Pieces[type_num][i][j];
            }
        }
        //cout << "33333";

        int flag=0, can=0;
        int place_row;
        for(int i=3; i<row+4; i++){
                //cout << "i:" << i << endl;
            for(int row_pie=3;row_pie>=0;row_pie--){
                //cout << "***" << i << " " << row_pie << "***" <<endl;
                int col_pie;
                for(col_pie=0; col_pie<4; col_pie++){
                    if(block_now[row_pie][col_pie] + game[i-(3-row_pie)][drop_pos+3+col_pie]==2){
                        flag=1;
                        cout << block_now[row_pie][col_pie] << " " << game[i-(3-row_pie)][drop_pos+3+col_pie] << endl;
                        cout << i-(3-row_pie) << drop_pos+3+col_pie << endl;
                        break;
                    }
                }
                if(flag==1){
                    can=1;
                    flag=0;
                    break;
                }
                else if(flag!=1 && row_pie==0 && col_pie==4 && i==row+3){
                    can=2;
                    break;
                }
            }
            cout << "can: " << can <<endl;
            if(can==1){
                can = 0;
                place_row = i-1;
                cout << "%%%" << place_row << endl;
                break;
            }
            else if(can==2){
                can = 0;
                place_row = i;
                cout << "&&&" << place_row << endl;
                break;
            }
        }
        //cout << "    " << place_row << "     " << "444444";
        for(int i=place_row, l=3;i>=0 && l>=0;i--, l--){
            for(int j=drop_pos+3, k=0;j<col+8 && k<4;j++, k++){
                //cout << "i=" << i << " " << "j=" << j << " " << "k=" << k << " " << "l=" << l << endl;
                game[i][j] += block_now[l][k];
                //cout << "&" << block_now[l][k] << " "<< game[i][j] << "&" << endl;
            }
        }

        //detect & delete row
        int count_one = 0;
        for(int i=4;i<row+4;i++){
            for(int j=4;j<col+4;j++){
                //cout << "i=" << i << " " << "j=" << j << " " << "k=" << k << " " << "l=" << l << endl;
                if(game[i][j]==1){
                    count_one++;
                }
                if(count_one==col){
                    for(int i=4;i<row+4;i++){
                        cout << "***";
                        for(j=4;j<col+4;j++){
                            cout << game[i][j];
                        }
                        cout << endl;
                    }
                    cout << "i:" << i << count_one << endl;
                    for (int row_move = i; row_move > 0; row_move--){
                        for (int col_move = 4; col_move < col+8; col_move++){
                            game[row_move][col_move] = game[row_move-1][col_move];
                        }
                    }
                }
                //cout << "&" << block_now[l][k] << " "<< game[i][j] << "&" << endl;
            }
                count_one = 0;
        }

        //cout << "55555";
        int game_over=0;
        for(int i=0;i<4;i++){
            for(int j=0, k=col+4;j<4;j++, k++){
                if(game[i][j]==1 || game[i][k]==1){
                    cout << "Game over";
                    game_over = 1;
                }
            }
        }

        for(int i=4; i<row+4; i++){
        for(int j=4;j<col+4;j++){
            //cout << i << " " << j << endl;
            cout << game[i][j];
        }
        cout << endl;
    }

        cin >> type;
        if(type=="End")
            break;
        cin >> drop_pos;
        if(game_over==1){
            cout << "break" << endl;
            break;
        }
    }


    return 0;
}
