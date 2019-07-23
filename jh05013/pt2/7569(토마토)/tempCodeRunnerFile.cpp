 else{
                    scanf("%d", &v[k][i][j]);
                    vector<int> t(3);
                    t[0] = k, t[1] = i, t[2] = j;
                    if(v[k][i][j] == 1)q.push(t);
                    else if(v[k][i][j] == 0) n++;
                }