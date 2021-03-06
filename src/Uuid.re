/* 16 byte array */
type bytesT = (
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
);

module V1 = {
  type t;
  type optionsT;
  [@bs.send] external toString : t => string = "";
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
    (~options: optionsT=?, ~buffer: array(int), ~offset: int, unit) => t =
    "uuid/v1";
};

module V3 = {
  type t;
  [@bs.send] external toString : t => string = "";
  [@bs.val] [@bs.module "uuid/v3"] external _DNS : string = "DNS";
  [@bs.val] [@bs.module "uuid/v3"] external _URL : string = "URL";
  [@bs.module]
  external create :
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)]
    ) =>
    t =
    "uuid/v3";
  [@bs.module]
  external createWithBuffer :
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)],
      ~buffer: array(int),
      ~offset: int=?,
      unit
    ) =>
    t =
    "uuid/v3";
};

module V4 = {
  type t;
  type optionsT;
  [@bs.send] external toString : t => string = "";
  [@bs.obj]
  external options :
    (~random: bytesT=?, ~rng: unit => bytesT=?, unit) => optionsT =
    "";
  [@bs.module] external create : unit => t = "uuid/v4";
  [@bs.module]
  external createWithOptions : (~options: optionsT) => t = "uuid/v4";
  [@bs.module]
  external createWithBuffer :
    (~options: optionsT=?, ~buffer: array(int), ~offset: int=?, unit) => t =
    "uuid/v4";
};

module V5 = {
  type t;
  [@bs.send] external toString : t => string = "";
  [@bs.val] [@bs.module "uuid/v5"] external _DNS : string = "DNS";
  [@bs.val] [@bs.module "uuid/v5"] external _URL : string = "URL";
  [@bs.module]
  external create :
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)]
    ) =>
    t =
    "uuid/v5";
  [@bs.module]
  external createWithBuffer :
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)],
      ~buffer: array(int),
      ~offset: int=?,
      unit
    ) =>
    t =
    "uuid/v5";
};
