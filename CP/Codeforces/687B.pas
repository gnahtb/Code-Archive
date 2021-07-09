uses
  math;
var
  n,k:longint;
  p,d:array[0..1000005] of longint;

procedure sieve;
var
  i,j:longint;
begin
  fillchar(p,sizeof(p),0);
  p[1]:=1;
  for i:=2 to 1000000 do p[i]:=i;
  for i:=2 to 1000 do
    if p[i]=i then
      for j:=2 to 1000000 div i do
        if p[i*j]>i then p[i*j]:=i;
end;

procedure fact(x:longint);
var
  tmp,pw:longint;
begin
  while x>1 do
    begin
      tmp:=p[x];
      pw:=0;
      while x mod tmp=0 do
        begin
          inc(pw);
          x:=x div tmp;
        end;
      d[tmp]:=max(d[tmp],pw);
    end;
end;

procedure enter;
var
  i,c:longint;
begin
  fillchar(d,sizeof(d),0);
  readln(n,k);
  for i:=1 to n do
    begin
      read(c);
      fact(c);
    end;
end;

procedure solve;
var
  i,j:longint;
  tmp,pd:int64;
begin
  pd:=1 mod int64(k);
  for i:=1 to 1000000 do
    if d[i]>0 then
      begin
        tmp:=1;
        for j:=1 to d[i] do tmp:=tmp*int64(i) mod int64(k);
        pd:=pd*tmp mod int64(k);
      end;
  if pd=0 then writeln('Yes')
  else writeln('No');
end;

begin
  sieve;
  enter;
  solve;
end.
