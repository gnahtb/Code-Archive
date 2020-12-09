{$MODE OBJFPC}
{$H+}
uses
  math;
type
  TArr=array[0..1000000] of longint;
var
  s1,s2:string;
  z1,z2:TArr;
  ans:longint;

function z_function(t,x:ansistring):TArr;
var
  s:string;
  i,l,r:longint;
  z:TArr;
begin
  s:=t+'*'+x;
  fillchar(z,sizeof(z),0);
  l:=1; r:=1;
  for i:=2 to length(s) do
    begin
      if i<=r then z[i]:=min(r-i+1,z[i-l+1]);
      while (i+z[i]<=length(s)) and (s[z[i]+1]=s[i+z[i]]) do inc(z[i]);
      if i+z[i]-1>r then
        begin
          l:=i;
          r:=i+z[i]-1;
        end;
    end;
  for i:=1 to length(x) do z[i]:=z[i+length(t)+1];
  z_function:=z;
end;

function check(x:longint):boolean;
var
  i:longint;
begin
  for i:=1 to length(s1) div x do
    if z1[(i-1)*x+1]<>x then exit(false);
  for i:=1 to length(s2) div x do
    if z2[(i-1)*x+1]<>x then exit(false);
  exit(true);
end;

procedure solve;
var
  i:longint;
  tmp:ansistring;
begin
  ans:=0; tmp:='';
  for i:=1 to min(length(s1),length(s2)) do
    begin
      tmp:=tmp+s1[i];
      if (length(s1) mod i=0) and (length(s2) mod i=0) then
        begin
          z1:=z_function(tmp,s1);
          z2:=z_function(tmp,s2);
          if check(i) then inc(ans);
        end;
    end;
end;

begin
  readln(s1);
  readln(s2);
  solve;
  writeln(ans);
end.
