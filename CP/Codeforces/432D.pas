{$MODE OBJFPC}
{$H+}
uses
  math;
type
  TArr=array[0..1000000] of longint;
var
  s:string;
  k:longint=1;
  a,c:TArr;


function z_function(p:string):TArr;
var
  z:TArr;
  i,l,r:longint;
begin
  fillchar(z,sizeof(z),0);
  l:=1; r:=1;
  for i:=2 to length(p) do
    begin
      if i<=r then z[i]:=min(z[i-l+1],r-i+1);
      while (i+z[i]<=length(p)) and (p[i+z[i]]=p[z[i]+1]) do inc(z[i]);
      if i+z[i]-1>r then
        begin
          l:=i;
          r:=i+z[i]-1;
        end;
    end;
  z_function:=z;
end;

procedure solve;
var
  i:longint;
begin
  fillchar(c,sizeof(c),0);
  c[1]:=1;
  for i:=2 to length(s) do
    if a[i]>0 then
      begin
        inc(c[1]);
        dec(c[a[i]+1]);
      end;
  for i:=1 to length(s) do c[i]:=c[i-1]+c[i];
  for i:=1 to length(s) do
    if a[length(s)-i+1]=i then inc(k);
  writeln(k);
  for i:=1 to length(s) do
    if a[length(s)-i+1]=i then writeln(i,' ',c[i]);
  writeln(length(s),' ',1);
end;

begin
  readln(s);
  a:=z_function(s);
  solve;
end.
