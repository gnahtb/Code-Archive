uses
  math;
var
  c:array[0..505] of longint;
  f:array[0..505,0..505] of longint;
  n,i,j,k,l:longint;
begin
  readln(n);
  for i:=1 to n do read(c[i]);
  fillchar(f,sizeof(f),0);
  for l:=1 to n do
    for i:=1 to n do
      begin
        j:=i+l-1;
        if i=j then f[i,j]:=1
        else
          begin
            f[i,j]:=f[i+1,j]+1;
            if c[i]=c[i+1] then f[i,j]:=min(f[i,j],f[i+2,j]+1);
            for k:=i+2 to j do
              if c[i]=c[k] then f[i,j]:=min(f[i,j],f[i+1,k-1]+f[k+1,j]);
          end;
      end;
  writeln(f[1,n]);
end.
