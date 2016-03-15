{
  "targets": [
    {
      "target_name": "evshammer",
      "sources": [ "EvsHammer.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
		"Hammer"
      ],
	  'conditions': [
        ['OS=="win"',
          {
	        'libraries': [
              '..\Hammer\Hammer_d.lib'
            ]
	      }
		]
	  ]
    }
  ]
}