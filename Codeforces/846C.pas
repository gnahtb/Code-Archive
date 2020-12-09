uses
  math;
var
  n:longint;
  a,delim:array[0..5005] of int64;
  f,prev:array[0..5,0..5005] of int64;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
end;

procedure solve;
var
  i,j,k:longint;
  s,t:int64;
begin
  fillchar(f,sizeof(f),0);
  fillchar(prev,sizeof(prev),0);
  for i:=1 to n do f[1,i]:=f[1,i-1]+a[i];
  for k:=2 to 4 do
    for i:=1 to n do
      begin
        s:=0;
        f[k,i]:=f[k-1,i];
        prev[k,i]:=i+1;
        for j:=i downto 1 do
          begin
            s+=a[j];
            t:=f[k-1,j-1]+s;
            if not odd(k) then t:=f[k-1,j-1]-s;
            if f[k,i]<t then
              begin
                f[k,i]:=t;
                prev[k,i]:=j;
              end;
          end;
      end;
end;

procedure trace;
var
  i,p:longint;
begin
  p:=n;
  for i:=4 downto 2 do
    begin
      p:=prev[i,p]-1;
      delim[i]:=p;
    end;
  write(delim[2],' ',delim[3],' ',delim[4]);
end;

begin
  enter;
  solve;
  trace;
end.
