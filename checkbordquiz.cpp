if ((row/10) % 2 == 0){
    if ((col) % 2 == 0){
        out[row][col] = img[row][col];
        }
    else{
        out[row][col] = 0;
    }
    }
    else{
    if ((col) % 2 == 0){
        out[row][col] = 0; 
    }
    else{
        out[row][col] = img[row][col];
    }
    }