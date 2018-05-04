module V1 = {
  type t;
  type optionsT;
  [@bs.obj]
  external options :
    (
      ~node: (int, int, int, int, int, int)=?,
      ~clockseq: int=?,
      ~msecs: int=?,
      ~nsecs: int=?,
      unit
    ) =>
    optionsT =
    "";
  [@bs.module] external create : unit => t = "uuid/v1";
  [@bs.module]
  external createWithOptions : (~options: optionsT) => t = "uuid/v1";
  [@bs.module]
  external createWithBuffer :
    (~options: optionsT=?, ~buffer: Buffer.t, ~offset: int, unit) => t =
    "uuid/v1";
  [@bs.send] external toString : t => string = "";
};

module V3 = {
  type t;
  [@bs.module]
  external create : (~name: string, ~namespace: string) => t = "uuid/v3";
  [@bs.send] external toString : t => string = "";
};
