uses
  math;
const
  inf=trunc(2E18);
  f0='What are you doing at the end of the world? Are you busy? Will you save us?';
  p1='What are you doing while sending "';
  p2='"? Are you busy? Will you send "';
  p3='"?';
var
  q,n,k:int64;
  len:array[0..100005] of int64;

procedure prep;
var
  i:longint;
begin
  fillchar(len,sizeof(len),0);
  len[0]:=75;
  for i:=1 to 100000 do len[i]:=min(inf,len[i-1]+len[i-1]+68);
end;

procedure solve;
begin
  while n>0 do
    begin
      if k<=34 then begin write(p1[k]); exit; end;
      k:=k-34;
      if k<=len[n-1] then begin dec(n); continue; end;
      k:=k-len[n-1];
      if k<=32 then begin write(p2[k]); exit; end;
      k:=k-32;
      if k<=len[n-1] then begin dec(n); continue; end;
      k:=k-len[n-1];
      if k<=2 then write(p3[k])
      else write('.');
      exit;
    end;
  if k<=75 then write(f0[k]) else write('.');
end;

begin
  prep;
  readln(q);
  while q>0 do
    begin
      readln(n,k);
      solve;
      dec(q);
    end;
end.
