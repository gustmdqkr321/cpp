int ***makeArray3D(int *sz){
  int n1 = sz[0];
  int n2 = sz[1];
  int n3 = sz[2];
  int ***arr = new int **[n1];
  for(int i = 0; i<n1; i++){
    arr[i] = new int *[n2];
    for(int j = 0; j<n2;j++){
      arr[i][j] = new int[n3];
    }
  }
  return arr;
}
void destroyArray3D(int ***arr,int *sz){
  int n1 = sz[0];
  int n2 = sz[1];
  for(int i=0; i<n1; i++){
    for(int j=0; j<n2; j++){
      delete[] arr[i][j];
    }
    delete[] arr[i];
  }
  delete[] arr;
}
