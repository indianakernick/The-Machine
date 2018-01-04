{
  checkParams(params, validNames)::
    local paramNames = std.set(std.objectFields(params));
    local invalidNames = std.setDiff(paramNames, std.set(validNames));
  {
    [if (std.length(invalidNames) > 0) then
      error "Invalid parameters: " + invalidNames
    ]:: null
  }
}
