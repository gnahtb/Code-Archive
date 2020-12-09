{$H+}
var
  n,k:longint;
  s:string;
  f:array[0..1005,-1005..1005] of string;

procedure solve;
var
  i,j:longint;
begin
  for i:=0 to 1005 do
    for j:=-1005 to 1005 do f[i,j]:='#';
  f[0,0]:='';
  for i:=1 to n do
    for j:=-k to k do
      if s[i]='?' then
        begin
          if (j-1>-k) and (f[i-1,j-1]<>'#') then f[i,j]:=f[i-1,j-1]+'W';
          if (j+1<k) and (f[i-1,j+1]<>'#') then f[i,j]:=f[i-1,j+1]+'L';
          if (j<k) and (j>-k) and (f[i-1,j]<>'#') then f[i,j]:=f[i-1,j]+'D';
        end
      else
        begin
          if (s[i]='W') and (j-1>-k) and (f[i-1,j-1]<>'#') then
            f[i,j]:=f[i-1,j-1]+'W';
          if (s[i]='L') and (j+1<k) and (f[i-1,j+1]<>'#') then
            f[i,j]:=f[i-1,j+1]+'L';
          if (s[i]='D') and (j<k) and (j>-k) and (f[i-1,j]<>'#') then
            f[i,j]:=f[i-1,j]+'D';
        end;
end;

begin
  readln(n,k);
  readln(s);
  solve;
  if (f[n,k]='#') and (f[n,-k]='#') then write('NO')
  else if (f[n,k]<>'#') then write(f[n,k])
  else write(f[n,-k]);
end.
