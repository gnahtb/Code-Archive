{$H+}
uses
  math;
const
  maxLength=trunc(1E5)+5;
type
  TIntList=array[0..maxLength] of longint;
  TBoolList=array[0..maxLength] of boolean;
var
  s,t:string;
  n,m:longint;
  zt,f,g:TIntList;
  cs,ct:TBoolList;

function z_func(p:string):TIntList;
var
  i,l,r:longint;
  z:TIntList;
begin
  fillchar(z,sizeof(z),0);
  l:=1;
  r:=1;
  for i:=2 to length(p) do
    begin
      if i<=r then z[i]:=min(z[i-l+1],r-i+1);
      while (i+z[i]<=length(p)) and (p[z[i]+1]=p[z[i]+i]) do
        inc(z[i]);
      if i+z[i]-1>r then
        begin
          l:=i;
          r:=i+z[i]-1;
        end;
    end;
  z_func:=z;
end;

procedure prep;
var
  i,j:longint;
begin
  fillchar(cs,sizeof(cs),false);
  fillchar(ct,sizeof(ct),false);
  for i:=1 to m do ct[i]:=(zt[i]=m-i+1);
  for i:=m to n do
    begin
      cs[i]:=true;
      for j:=1 to m do
        if (s[i+j-m]<>t[j]) and (s[i+j-m]<>'?') then
          begin
            cs[i]:=false;
            break;
          end;
    end;
end;

procedure solve;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(g,sizeof(g),0);
  for i:=1 to n do
    begin
      if cs[i] then
        begin
          f[i]:=g[i-m];
          for j:=1 to m-1 do
            if ct[m-j+1] then f[i]:=max(f[i],f[i+j-m]);
          inc(f[i]);
        end;
      g[i]:=max(g[i-1],f[i]);
    end;
end;

begin
  readln(s);
  readln(t);
  n:=length(s);
  m:=length(t);
  zt:=z_func(t);
  prep;
  solve;
  writeln(g[n]);
end.
