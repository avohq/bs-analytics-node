type t;

type userIdentifier 'a = Js.t {. userId : string, traits : Js.nullable (Js.Dict.t 'a)};

type eventIdentifier 'a =
  Js.t {. userId : string, properties : Js.nullable (Js.Dict.t 'a), event : string};

external make : string => t = "analytics-node" [@@bs.module] [@@bs.new];

external identify : userIdentifier 'a => t = "" [@@bs.send.pipe : t];

external track : eventIdentifier 'a => t = "" [@@bs.send.pipe : t];

let identify ::userId ::traits => identify {"userId": userId, "traits": Js.Nullable.return traits};

let track ::userId ::event ::properties =>
  track {"userId": userId, "event": event, "properties": Js.Nullable.return properties};
