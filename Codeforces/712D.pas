uses
  math;
const
  limit=trunc(2E5)+5;
  modulo=trunc(1E9)+7;
var
  a,b,k,t:longint;
  ans:int64;
  f,g:array[-limit..limit] of int64;

procedure solve;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(g,sizeof(g),0);
  f[0]:=1;
  for i:=1 to t do
    begin
      for j:=-k*t to k*t do g[j]:=(g[j-1]+f[j]) mod modulo;
      for j:=-k*t to k*t do f[j]:=(g[min(j+k,k*t)]-g[max(j-k-1,-k*t-1)]+modulo) mod modulo;
    end;
  ans:=0;
  for j:=-k*t to k*t do g[j]:=(g[j-1]+f[j]) mod modulo;
  for j:=-k*t to k*t do
    ans:=(ans+f[j]*g[min(max(j+a-b-1,-k*t-1),k*t)]) mod modulo;
end;

begin
  readln(a,b,k,t);
  solve;
  writeln(ans);
end.
