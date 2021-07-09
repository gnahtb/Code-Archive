{$H+}
uses
  math;
const
  module=trunc(1E9)+7;
var
  n:longint;
  a:array['a'..'z'] of longint;
  f1,f2,f3:array[0..1005] of int64;
  s:string;

procedure enter;
var
  i:char;
begin
  readln(n);
  readln(s);
  for i:='a' to 'z' do read(a[i]);
end;

procedure solve;
var
  i,j,t:longint;
begin
  fillchar(f1,sizeof(f1),0);
  fillchar(f2,sizeof(f2),0);
  fillchar(f3,sizeof(f3),0);
  f1[0]:=1;
  for i:=1 to n do
    begin
      j:=i;
      t:=a[s[i]];
      while (j>1) and (min(t,a[s[j-1]])>=i-j+2) do
        begin
          dec(j);
          t:=min(t,a[s[j]]);
        end;
      for j:=j to i do
        begin
          f1[i]:=(f1[i]+f1[j-1]) mod module;
          f2[i]:=max(f2[i],max(f2[j-1],i-j+1));
          if f3[i]<=0 then f3[i]:=f3[j-1]+1
          else f3[i]:=min(f3[i],f3[j-1]+1);
        end;
    end;
end;

begin
  enter;
  solve;
  writeln(f1[n]);
  writeln(f2[n]);
  writeln(f3[n]);
end.
