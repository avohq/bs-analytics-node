type t;

type userIdentifier 'a = Js.t {. traits : Js.nullable (Js.Dict.t 'a), userId : string};

type eventIdentifier 'a =
  Js.t {. event : string, properties : Js.nullable (Js.Dict.t 'a), userId : string};

let make: string => t;

let identify: userId::string => traits::Js.Dict.t 'a => t => t;

let track: userId::string => event::string => properties::Js.Dict.t 'a => t => t;
