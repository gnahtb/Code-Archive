{$MODE OBJFPC}
var
  k,x,ans1,ans2:longint;
  cnt:array[0..2000] of longint;

procedure enter;
var
  n,a:longint;
begin
  fillchar(cnt,sizeof(cnt),0);
  readln(n,k,x);
  for n:=n downto 1 do
    begin
      read(a);
      inc(cnt[a]);
    end;
end;

procedure solve;
var
  i,pref,d:longint;
  tmp:array[0..2000] of longint;
begin
  for k:=k downto 1 do
    begin
      fillchar(tmp,sizeof(tmp),0);
      pref:=0;
      for i:=0 to 1024 do
        if cnt[i]>0 then
          begin
            d:=cnt[i] >> 1;
            if (pref and 1=0) and (cnt[i] and 1=1) then inc(d);
            tmp[i xor x]+=d;
            tmp[i]+=cnt[i]-d;
            pref+=cnt[i];
          end;
      for i:=0 to 1024 do cnt[i]:=tmp[i];
    end;
  for i:=0 to 1024 do if cnt[i]>0 then ans1:=i;
  for i:=1024 downto 0 do if cnt[i]>0 then ans2:=i;
end;

begin
  enter;
  solve;
  writeln(ans1,' ',ans2);
end.
