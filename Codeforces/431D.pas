var
  c:array[0..70,0..70] of int64;
  m,k:int64;

procedure prep;
var
  i,j:longint;
begin
  fillchar(c,sizeof(c),0);
  c[0,0]:=1;
  for i:=1 to 65 do
    begin
      c[i,0]:=1;
      for j:=1 to i do
        c[i,j]:=c[i-1,j]+c[i-1,j-1];
    end;
end;

function calc(x:int64):int64;
var
  sum:int64;
  i,cnt:longint;
begin
  cnt:=0;
  sum:=0;
  for i:=63 downto 1 do
    if (x shr int64(i)) and 1=1 then
      begin
        if k>cnt then sum:=sum+c[i-1,k-cnt-1];
        if k>=cnt then sum:=sum+c[i-1,k-cnt];
        inc(cnt);
      end;
  calc:=sum;
end;

procedure solve;
var
  left,right,mid,t1,t2:int64;
begin
  left:=1;
  right:=trunc(1E18);
  while left<=right do
    begin
      mid:=(left+right) div 2;
      t1:=calc(mid);
      t2:=calc(mid*2);
      if t2-t1>m then right:=mid-1;
      if t2-t1<m then left:=mid+1;
      if t2-t1=m then
        begin
          write(mid);
          halt;
        end;
    end;
end;

begin
  readln(m,k);
  prep;
  solve;
end.
