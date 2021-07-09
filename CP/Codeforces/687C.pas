{$MODE OBJFPC}
uses
  gvector;
type
  TIntVector=specialize TVector<longint>;
var
  i,j,k,n,s:longint;
  c:array[0..505] of longint;
  f:array[0..505,0..505,0..505] of boolean;
  ans:TIntVector;
begin
  readln(n,s);
  for i:=1 to n do read(c[i]);
  fillchar(f,sizeof(f),false);
  f[0,0,0]:=true;
  for i:=1 to n do
    for k:=0 to s do
      for j:=0 to k do
        begin
          f[i,k,j]:=f[i-1,k,j];
          if k>=c[i] then f[i,k,j]:=f[i,k,j] or f[i-1,k-c[i],j];
          if j>=c[i] then f[i,k,j]:=f[i,k,j] or f[i-1,k-c[i],j-c[i]];
        end;
  ans:=TIntVector.create;
  for i:=0 to s do
    if f[n,s,i] then ans.pushback(i);
  writeln(ans.size);
  for i:=0 to ans.size-1 do write(ans[i],' ');
end.
