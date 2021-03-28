{
  "routing_settings": {
    "bus_wait_time": 6,
    "bus_velocity": 40
  },
  "base_requests": [
    {
      "type": "Bus",
      "name": "297",
      "stops": [
        "Biryulyovo Zapadnoye",
        "Biryulyovo Tovarnaya",
        "Universam",
        "Biryulyovo Zapadnoye"
      ],
      "is_roundtrip": true
    },
    {
      "type": "Bus",
      "name": "635",
      "stops": [
        "Biryulyovo Tovarnaya",
        "Universam",
        "Prazh"
      ],
      "is_roundtrip": false
    },
    {
      "type": "Stop",
      "road_distances": {
        "Biryulyovo Tovarnaya": 2600
      },
      "longitude": 37.6517,
      "name": "Biryulyovo Zapadnoye",
      "latitude": 55.574371
    },
    {
      "type": "Stop",
      "road_distances": {
        "Prazh": 4650,
        "Biryulyovo Tovarnaya": 1380,
        "Biryulyovo Zapadnoye": 2500
      },
      "longitude": 37.645687,
      "name": "Universam",
      "latitude": 55.587655
    },
    {
      "type": "Stop",
      "road_distances": {
        "Universam": 890
      },
      "longitude": 37.653656,
      "name": "Biryulyovo Tovarnaya",
      "latitude": 55.592028
    },
    {
      "type": "Stop",
      "road_distances": {},
      "longitude": 37.603938,
      "name": "Prazh",
      "latitude": 55.611717
    }
  ],
  "stat_requests": [
    {
      "type": "Bus",
      "name": "297",
      "id": 1
    },
    {
      "type": "Bus",
      "name": "635",
      "id": 2
    },
    {
      "type": "Stop",
      "name": "Universam",
      "id": 3
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Universam",
      "id": 4
    },
    {
      "type": "Route",
      "from": "Biryulyovo Zapadnoye",
      "to": "Prazh"
    }
  ]
}

{"base_requests": [{"type": "Stop", "name": "Tolstopaltsevo", "latitude": 55.611087, "longitude": 37.20829, "road_distances": {"Marushkino": 3900}}, {"type": "Stop", "name": "Marushkino", "latitude": 55.595884, "longitude": 37.209755, "road_distances": {"Rasskazovka": 9900}}, {"type": "Bus", "name": "256", "stops": ["Biryulyovo Zapadnoye", "Biryusinka", "Universam", "Biryulyovo Tovarnaya", "Biryulyovo Passazhirskaya", "Biryulyovo Zapadnoye"], "is_roundtrip": true}, {"type": "Bus", "name": "750", "stops": ["Tolstopaltsevo", "Marushkino", "Rasskazovka"], "is_roundtrip": false}, {"type": "Stop", "name": "Rasskazovka", "latitude": 55.632761, "longitude": 37.333324, "road_distances": {}}, {"type": "Stop", "name": "Biryulyovo Zapadnoye", "latitude": 55.574371, "longitude": 37.6517, "road_distances": {"Biryusinka": 1800, "Universam": 2400, "Rossoshanskaya ulitsa": 7500}}, {"type": "Stop", "name": "Biryusinka", "latitude": 55.581065, "longitude": 37.64839, "road_distances": {"Universam": 750}}, {"type": "Stop", "name": "Universam", "latitude": 55.587655, "longitude": 37.645687, "road_distances": {"Biryulyovo Tovarnaya": 900, "Rossoshanskaya ulitsa": 5600}}, {"type": "Stop", "name": "Biryulyovo Tovarnaya", "latitude": 55.592028, "longitude": 37.653656, "road_distances": {"Biryulyovo Passazhirskaya": 1300}}, {"type": "Stop", "name": "Biryulyovo Passazhirskaya", "latitude": 55.580999, "longitude": 37.659164, "road_distances": {"Biryulyovo Zapadnoye": 1200}}, {"type": "Bus", "name": "828", "stops": ["Biryulyovo Zapadnoye", "Universam", "Rossoshanskaya ulitsa", "Biryulyovo Zapadnoye"], "is_roundtrip": true}, {"type": "Stop", "name": "Rossoshanskaya ulitsa", "latitude": 55.595579, "longitude": 37.605757, "road_distances": {}}, {"type": "Stop", "name": "Prazhskaya", "latitude": 55.611678, "longitude": 37.603831, "road_distances": {}}], "stat_requests": [{"id": 978185239, "type": "Bus", "name": "256"}, {"id": 288134312, "type": "Bus", "name": "750"}, {"id": 1323217495, "type": "Bus", "name": "751"}, {"id": 2051224190, "type": "Stop", "name": "Samara"}, {"id": 243786222, "type": "Stop", "name": "Prazhskaya"}, {"id": 605831345, "type": "Stop", "name": "Biryulyovo Zapadnoye"}]}

{"base_requests": [{"type": "Stop", "name": "Tolstopaltsevo", "latitude": 55.611087, "longitude": 37.20829, "road_distances": {"Marushkino": 3900}}, {"type": "Stop", "name": "Marushkino", "latitude": 55.595884, "longitude": 37.209755, "road_distances": {"Rasskazovka": 9900}}, {"type": "Bus", "name": "256", "stops": ["Biryulyovo Zapadnoye", "Biryusinka", "Universam", "Biryulyovo Tovarnaya", "Biryulyovo Passazhirskaya", "Biryulyovo Zapadnoye"], "is_roundtrip": "true"}, {"type": "Bus", "name": "750", "stops": ["Tolstopaltsevo", "Marushkino", "Rasskazovka"], "is_roundtrip": "false"}, {"type": "Stop", "name": "Rasskazovka", "latitude": 55.632761, "longitude": 37.333324, "road_distances": {}}, {"type": "Stop", "name": "Biryulyovo Zapadnoye", "latitude": 55.574371, "longitude": 37.6517, "road_distances": {"Biryusinka": 1800, "Universam": 2400, "Rossoshanskaya ulitsa": 7500}}, {"type": "Stop", "name": "Biryusinka", "latitude": 55.581065, "longitude": 37.64839, "road_distances": {"Universam": 750}}, {"type": "Stop", "name": "Universam", "latitude": 55.587655, "longitude": 37.645687, "road_distances": {"Biryulyovo Tovarnaya": 900, "Rossoshanskaya ulitsa": 5600}}, {"type": "Stop", "name": "Biryulyovo Tovarnaya", "latitude": 55.592028, "longitude": 37.653656, "road_distances": {"Biryulyovo Passazhirskaya": 1300}}, {"type": "Stop", "name": "Biryulyovo Passazhirskaya", "latitude": 55.580999, "longitude": 37.659164, "road_distances": {"Biryulyovo Zapadnoye": 1200}}, {"type": "Bus", "name": "828", "stops": ["Biryulyovo Zapadnoye", "Universam", "Rossoshanskaya ulitsa", "Biryulyovo Zapadnoye"], "is_roundtrip": "true"}, {"type": "Stop", "name": "Rossoshanskaya ulitsa", "latitude": 55.595579, "longitude": 37.605757, "road_distances": {}}, {"type": "Stop", "name": "Prazhskaya", "latitude": 55.611678, "longitude": 37.603831, "road_distances": {}}], "stat_requests": [{"id": 978185239, "type": "Bus", "name": "256"}, {"id": 288134312, "type": "Bus", "name": "750"}, {"id": 1323217495, "type": "Bus", "name": "751"}, {"id": 2051224190, "type": "Stop", "name": "Samara"}, {"id": 243786222, "type": "Stop", "name": "Prazhskaya"}, {"id": 605831345, "type": "Stop", "name": "Biryulyovo Zapadnoye"}]}



{"base_requests":
	[
	 {"type": "Stop",
	  "name": "Tolstopaltsevo",
	  "latitude": 55.611087,
	  "longitude": 37.20829,
	  "road_distances": {
		 "Marushkino": 3900
	 }
	 },
	 {"type": "Stop",
	  "name": "Marushkino",
	  "latitude": 55.595884,
	  "longitude": 37.209755,
	  "road_distances": {
		 "Rasskazovka": 9900
	 }
	 },
	 {"type": "Bus",
	  "name": "256",
	  "stops": [
				"Biryulyovo Zapadnoye",
				"Biryusinka", "Universam",
				"Biryulyovo Tovarnaya",
				"Biryulyovo Passazhirskaya",
				"Biryulyovo Zapadnoye"
				],
	  "is_roundtrip": true
	 },
	 {"type": "Bus",
	  "name": "750",
	  "stops": [
				"Tolstopaltsevo",
				"Marushkino",
				"Rasskazovka"
				],
	  "is_roundtrip": false
	 },
	 {"type": "Stop",
	  "name": "Rasskazovka",
	  "latitude": 55.632761,
	  "longitude": 37.333324,
	  "road_distances": {}
	 },
	 {"type": "Stop",
	  "name": "Biryulyovo Zapadnoye",
	  "latitude": 55.574371,
	  "longitude": 37.6517,
	  "road_distances": {
		 "Biryusinka": 1800,
		 "Universam": 2400,
		 "Rossoshanskaya ulitsa": 7500
	 }
	 },
	 {"type": "Stop",
	  "name": "Biryusinka",
	  "latitude": 55.581065,
	  "longitude": 37.64839,
	  "road_distances": {
		 "Universam": 750
	 }
	 },
	 {"type": "Stop",
	  "name": "Universam",
	  "latitude": 55.587655,
	  "longitude": 37.645687,
	  "road_distances": {
		 "Biryulyovo Tovarnaya": 900,
		 "Rossoshanskaya ulitsa": 5600
	 }
	 },
	 {"type": "Stop",
	  "name": "Biryulyovo Tovarnaya",
	  "latitude": 55.592028,
	  "longitude": 37.653656,
	  "road_distances": {
		 "Biryulyovo Passazhirskaya": 1300
	 }
	 },
	 {"type": "Stop",
	  "name": "Biryulyovo Passazhirskaya",
	  "latitude": 55.580999,
	  "longitude": 37.659164,
	  "road_distances": {
		 "Biryulyovo Zapadnoye": 1200
	 }
	 },
	 {"type": "Bus",
	  "name": "828",
	  "stops": [
				"Biryulyovo Zapadnoye",
				"Universam",
				"Rossoshanskaya ulitsa",
				"Biryulyovo Zapadnoye"
				],
	  "is_roundtrip": true
	 },
	 {"type": "Stop",
	  "name": "Rossoshanskaya ulitsa",
	  "latitude": 55.595579,
	  "longitude": 37.605757,
	  "road_distances": {
	 }
	 },
	 {"type": "Stop",
	  "name": "Prazhskaya",
	  "latitude": 55.611678,
	  "longitude": 37.603831,
	  "road_distances": {

	 }
	 }],
	 "stat_requests": [
	{
		"id": 978185239,
		"type": "Bus",
		"name": "256"
	},
	{
		"id": 288134312,
		"type": "Bus",
		"name": "750"
	},
	{
		"id": 1323217495,
		"type": "Bus",
		"name": "751"
	},
	{
		"id": 2051224190,
		"type": "Stop",
		"name": "Samara"
	},
	{
		"id": 243786222,
		"type":
		"Stop",
		"name": "Prazhskaya"
	},
	{
		"id": 605831345,
		"type": "Stop",
		"name": "Biryulyovo Zapadnoye"
	}]
}




{"base_requests":
	[
	 {"type": "Stop",
	  "name": "Tolstopaltsevo",
	  "latitude": 55.611087,
	  "longitude": 37.20829,
	  "road_distances": {
		 "Marushkino": 3900
	 }
	 },
	 {"type": "Stop",
	  "name": "Marushkino",
	  "latitude": 55.595884,
	  "longitude": 37.209755,
	  "road_distances": {
		 "Rasskazovka": 9900
	 }
	 },
	 {"type": "Bus",
	  "name": "256",
	  "stops": [
				"Biryulyovo Zapadnoye",
				"Biryusinka", "Universam",
				"Biryulyovo Tovarnaya",
				"Biryulyovo Passazhirskaya",
				"Biryulyovo Zapadnoye"
				],
	  "is_roundtrip": "true"
	 },
	 {"type": "Bus",
	  "name": "750",
	  "stops": [
				"Tolstopaltsevo",
				"Marushkino",
				"Rasskazovka"
				],
	  "is_roundtrip": "false"
	 },
	 {"type": "Stop",
	  "name": "Rasskazovka",
	  "latitude": 55.632761,
	  "longitude": 37.333324,
	  "road_distances": {}
	 },
	 {"type": "Stop",
	  "name": "Biryulyovo Zapadnoye",
	  "latitude": 55.574371,
	  "longitude": 37.6517,
	  "road_distances": {
		 "Biryusinka": 1800,
		 "Universam": 2400,
		 "Rossoshanskaya ulitsa": 7500
	 }
	 },
	 {"type": "Stop",
	  "name": "Biryusinka",
	  "latitude": 55.581065,
	  "longitude": 37.64839,
	  "road_distances": {
		 "Universam": 750
	 }
	 },
	 {"type": "Stop",
	  "name": "Universam",
	  "latitude": 55.587655,
	  "longitude": 37.645687,
	  "road_distances": {
		 "Biryulyovo Tovarnaya": 900,
		 "Rossoshanskaya ulitsa": 5600
	 }
	 },
	 {"type": "Stop",
	  "name": "Biryulyovo Tovarnaya",
	  "latitude": 55.592028,
	  "longitude": 37.653656,
	  "road_distances": {
		 "Biryulyovo Passazhirskaya": 1300
	 }
	 },
	 {"type": "Stop",
	  "name": "Biryulyovo Passazhirskaya",
	  "latitude": 55.580999,
	  "longitude": 37.659164,
	  "road_distances": {
		 "Biryulyovo Zapadnoye": 1200
	 }
	 },
	 {"type": "Bus",
	  "name": "828",
	  "stops": [
				"Biryulyovo Zapadnoye",
				"Universam",
				"Rossoshanskaya ulitsa",
				"Biryulyovo Zapadnoye"
				],
	  "is_roundtrip": "true"
	 },
	 {"type": "Stop",
	  "name": "Rossoshanskaya ulitsa",
	  "latitude": 55.595579,
	  "longitude": 37.605757,
	  "road_distances": {
	 }
	 },
	 {"type": "Stop",
	  "name": "Prazhskaya",
	  "latitude": 55.611678,
	  "longitude": 37.603831,
	  "road_distances": {

	 }
	 }],
	 "stat_requests": [
	{
		"id": 978185239,
		"type": "Bus",
		"name": "256"
	},
	{
		"id": 288134312,
		"type": "Bus",
		"name": "750"
	},
	{
		"id": 1323217495,
		"type": "Bus",
		"name": "751"
	},
	{
		"id": 2051224190,
		"type": "Stop",
		"name": "Samara"
	},
	{
		"id": 243786222,
		"type":
		"Stop",
		"name": "Prazhskaya"
	},
	{
		"id": 605831345,
		"type": "Stop",
		"name": "Biryulyovo Zapadnoye"
	}]
}
