const
  module=trunc(1E9)+7;
  p:array[0..18] of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67);
var
  cnt:array[0..70] of longint;
  pw2,f:array[0..524288] of int64;
  ans:int64;

procedure prep;
var
  i:longint;
begin
  fillchar(pw2,sizeof(pw2),0);
  pw2[0]:=1;
  for i:=1 to 100000 do pw2[i]:=pw2[i-1]*2 mod module;
end;

procedure enter;
var
  a,n:longint;
begin
  fillchar(cnt,sizeof(cnt),0);
  readln(n);
  while n>0 do
    begin
      read(a);
      inc(cnt[a]);
      dec(n);
    end;
end;

procedure solve;
var
  i,j,b,t,c:longint;
  tmp:int64;
  g:array[0..524288] of int64;
begin
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  for i:=1 to 70 do
    if cnt[i]>0 then
      begin
        b:=0;
        t:=i;
        for j:=0 to 18 do 
          begin
            c:=0;
            while t mod p[j]=0 do
              begin
                inc(c);
                t:=t div p[j];
              end;
            if odd(c) then b:=b+1 shl j;
          end;
        if b>0 then
          begin
            fillchar(g,sizeof(g),0);
            for j:=0 to (1 shl 19)-1 do
              if f[j]>0 then
                begin
                  t:=b xor j;
                  tmp:=f[j]*pw2[cnt[i]-1] mod module;
                  g[t]:=(g[t]+tmp) mod module;
                  g[j]:=(g[j]+tmp) mod module;
                end;
            for j:=0 to (1 shl 19)-1 do f[j]:=g[j];
          end
        else for j:=0 to (1 shl 19)-1 do f[j]:=f[j]*pw2[cnt[i]] mod module;
      end;
  ans:=(f[0]-1+module) mod module;
end;

begin
  prep;
  enter;
  solve;
  writeln(ans);
end.
