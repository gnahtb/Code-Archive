var
  i,j,x,t,n,k:longint;
  c:array[0..15] of longint;

function getBit(state,p:longint):longint;
begin
  getBit:=(state shr (p-1)) and 1;
end;

function check(state1,state2:longint):boolean;
var
  k:longint;
begin
  for k:=1 to 4 do
    if getBit(state1,k)+getBit(state2,k)=2 then exit(false);
  check:=true;
end;

begin
  readln(n,k);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
    begin
      x:=0;
      for j:=1 to k do
        begin
          read(t);
          x+=t*(1 shl (j-1));
        end;
      inc(c[x]);
      readln;
    end;
  if c[0]>0 then
    begin
      write('yes');
      halt;
    end;
  for i:=1 to 1 shl k-1 do
    for j:=1 to 1 shl k-1 do
      if check(i,j) and (c[i]>0) and (c[j]>0) then
        begin
          write('yes');
          halt;
        end;
  write('no');
end.
