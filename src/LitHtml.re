module D = Webapi.Dom;

module Partial = {
  type t('a);
};

module RenderOptions = {
  type t;
};

module TemplateResult = {
  type t;
};

[@bs.send]
external render:
  (
    TemplateResult.t,
    [@bs.unwrap] [
      | `element(D.Element.t)
      | `documentFragment(D.DocumentFragment.t)
    ],
    ~options: Partial.t(RenderOptions.t)=?,
    unit
  ) =>
  unit =
  "";

type templateLiteral;
[@bs.send] external html: templateLiteral => TemplateResult.t = "";
[@bs.send] external svg: templateLiteral => TemplateResult.t = "";