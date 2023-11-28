import GeoJSON from "ol/format/GeoJSON.js";
import Layer from "ol/layer/Layer.js";
import Map from "ol/Map.js";
import View from "ol/View.js";
import WebGLVectorLayerRenderer from "ol/renderer/webgl/VectorLayer.js";
import { Draw, Modify, Snap } from "ol/interaction.js";
import { OSM, Vector as VectorSource } from "ol/source.js";
import { Tile as TileLayer } from "ol/layer.js";
import { fromLonLat } from "ol/proj.js";

/**
 * @type {import('ol/style/webgl.js').WebGLStyle}
 */
let style;
let es;
let swiss = {
	type: "FeatureCollection",
	features: [
		{
			type: "Feature",
			id: "CHE",
			properties: { name: "Switzerland" },
			geometry: {
				type: "Polygon",
				coordinates: [
					[
						[9.594226, 47.525058],
						[9.632932, 47.347601],
						[9.47997, 47.10281],
						[9.932448, 46.920728],
						[10.442701, 46.893546],
						[10.363378, 46.483571],
						[9.922837, 46.314899],
						[9.182882, 46.440215],
						[8.966306, 46.036932],
						[8.489952, 46.005151],
						[8.31663, 46.163642],
						[7.755992, 45.82449],
						[7.273851, 45.776948],
						[6.843593, 45.991147],
						[6.5001, 46.429673],
						[6.022609, 46.27299],
						[6.037389, 46.725779],
						[6.768714, 47.287708],
						[6.736571, 47.541801],
						[7.192202, 47.449766],
						[7.466759, 47.620582],
						[8.317301, 47.61358],
						[8.522612, 47.830828],
						[9.594226, 47.525058],
					],
				],
			},
		},
	],
};

class WebGLLayer extends Layer {
	createRenderer() {
		return new WebGLVectorLayerRenderer(this, {
			className: this.getClassName(),
			style,
		});
	}
}

style = {
	variables: style ? style.variables : { width: 4 },
	"stroke-width": ["var", "width"],
	"stroke-color": "#000",
};

const source = new VectorSource({
	url: "data/geojson/southamericamemes.geojson",
	format: new GeoJSON(),
});

// const sourceEuro = new VectorSource({
// 	url: "data/geojson/switzerland.geojson",
// 	format: new GeoJSON(),
// });

let vector = new WebGLLayer({
	source,
});

var vectorSource = new VectorSource({
	features: new GeoJSON().readFeatures(swiss, {
		featureProjection: "EPSG:3857", // Projeção do OpenLayers
		dataProjection: "EPSG:4326", // Projeção do GeoJSON
	}),
});

var vectorLayer = new WebGLLayer({
	source: vectorSource,
});

const map = new Map({
	layers: [new TileLayer({ source: new OSM() }), vector, vectorLayer],
	target: "map",
	view: new View({ center: fromLonLat([-40.074471, -19.415788]), zoom: 0 }),
});

// map.addLayer(vectorLayer);

// const rebuildStyle = () => {
// 	style = {
// 		variables: style ? style.variables : { width: 4 },
// 		"stroke-width": ["var", "width"],
// 		"stroke-color": "#000",
// 	};
// 	map.removeLayer(vector);
// 	vector = new WebGLLayer({
// 		source,
// 	});
// 	map.addLayer(vector);
// };

// const modify = new Modify({ source: source });
// map.addInteraction(modify);

// let draw, snap; // global so we can remove them later

// function addInteractions() {
// 	draw = new Draw({
// 		source: source,
// 		type: "LineString",
// 	});
// 	map.addInteraction(draw);
// 	snap = new Snap({ source: source });
// 	map.addInteraction(snap);
// }

// addInteractions();

// const inputListener = (event) => {
// 	const variables = style.variables;
// 	const variableName = event.target.name;
// 	if (event.target.type === "radio") {
// 		variables[variableName] = event.target.value;
// 	} else {
// 		variables[variableName] = parseFloat(event.target.value);
// 	}
// 	const valueSpan = document.getElementById(`value-${variableName}`);
// 	if (valueSpan) {
// 		valueSpan.textContent = variables[variableName];
// 	}
// 	map.render();
// };
// document.querySelectorAll("input.uniform").forEach((input) => input.addEventListener("input", inputListener));
// document.querySelectorAll("input.rebuild").forEach((input) => input.addEventListener("input", rebuildStyle));
es = {
	type: "FeatureCollection",
	features: [
		{
			geometry: {
				coordinates: [
					[
						[
							[-29.33288, -20.57969],
							[-29.33825, -20.58416],
							[-29.34826, -20.56129],
							[-29.34431, -20.55096],
							[-29.33202, -20.55332],
							[-29.31688, -20.56878],
							[-29.32396, -20.57147],
							[-29.3286, -20.57529],
							[-29.33288, -20.57969],
						],
					],
					[
						[
							[-28.88126, -20.51686],
							[-28.88329, -20.51873],
							[-28.88191, -20.51539],
							[-28.88142, -20.51238],
							[-28.88048, -20.51084],
							[-28.87706, -20.51165],
							[-28.87784, -20.51426],
							[-28.87926, -20.51572],
							[-28.88126, -20.51686],
						],
					],
					[
						[
							[-40.31678, -20.27516],
							[-40.31392, -20.28271],
							[-40.30816, -20.28217],
							[-40.30499, -20.27866],
							[-40.29233, -20.28378],
							[-40.29116, -20.28999],
							[-40.29058, -20.29836],
							[-40.29143, -20.30322],
							[-40.29889, -20.30755],
							[-40.30843, -20.31214],
							[-40.3093, -20.31242],
							[-40.32595, -20.3162],
							[-40.34536, -20.31618],
							[-40.35616, -20.31567],
							[-40.35794, -20.30811],
							[-40.35222, -20.30028],
							[-40.34235, -20.28706],
							[-40.33351, -20.27623],
							[-40.32023, -20.27192],
							[-40.31678, -20.27516],
						],
					],
					[
						[
							[-40.35895, -17.91932],
							[-40.35391, -17.92097],
							[-40.33614, -17.92097],
							[-40.3311, -17.92273],
							[-40.32709, -17.92568],
							[-40.3235, -17.92924],
							[-40.32032, -17.93312],
							[-40.31306, -17.93994],
							[-40.30841, -17.94257],
							[-40.30286, -17.94423],
							[-40.29658, -17.945],
							[-40.28986, -17.9449],
							[-40.27738, -17.9435],
							[-40.27105, -17.94381],
							[-40.2655, -17.94521],
							[-40.26072, -17.94764],
							[-40.25645, -17.95058],
							[-40.25294, -17.9541],
							[-40.24498, -17.96045],
							[-40.24059, -17.96324],
							[-40.2357, -17.96547],
							[-40.21689, -17.97193],
							[-40.20684, -17.97854],
							[-40.18449, -18.00934],
							[-39.67261, -18.32322],
							[-39.72468, -18.51873],
							[-39.74486, -18.68174],
							[-39.74108, -18.90211],
							[-39.71923, -19.09051],
							[-39.69807, -19.23992],
							[-39.70141, -19.37615],
							[-39.70979, -19.41611],
							[-39.7862, -19.60198],
							[-39.807, -19.63616],
							[-39.83487, -19.65716],
							[-39.951, -19.70517],
							[-40.00943, -19.747],
							[-40.02684, -19.76442],
							[-40.08365, -19.89544],
							[-40.08812, -19.91448],
							[-40.0974, -19.9306],
							[-40.14167, -19.94557],
							[-40.15705, -19.95892],
							[-40.13443, -19.95892],
							[-40.13199, -19.97186],
							[-40.14647, -20.02304],
							[-40.15388, -20.0276],
							[-40.16267, -20.02955],
							[-40.17003, -20.03395],
							[-40.17862, -20.04339],
							[-40.17748, -20.05853],
							[-40.1754, -20.06732],
							[-40.16609, -20.08652],
							[-40.16389, -20.09612],
							[-40.16592, -20.10589],
							[-40.1754, -20.12526],
							[-40.19099, -20.18987],
							[-40.19489, -20.1985],
							[-40.20254, -20.2077],
							[-40.22277, -20.25156],
							[-40.23278, -20.26678],
							[-40.24153, -20.27557],
							[-40.24437, -20.27752],
							[-40.24722, -20.27353],
							[-40.25609, -20.26377],
							[-40.26618, -20.26051],
							[-40.27355, -20.26751],
							[-40.27994, -20.27695],
							[-40.28673, -20.28102],
							[-40.29809, -20.2737],
							[-40.2932, -20.24505],
							[-40.3004, -20.23268],
							[-40.3164, -20.22796],
							[-40.33605, -20.22763],
							[-40.36929, -20.23268],
							[-40.35619, -20.24334],
							[-40.3509, -20.25652],
							[-40.35656, -20.26637],
							[-40.37613, -20.26678],
							[-40.37613, -20.27418],
							[-40.37173, -20.27557],
							[-40.36872, -20.27695],
							[-40.36189, -20.28102],
							[-40.37047, -20.30104],
							[-40.36597, -20.32323],
							[-40.34788, -20.32621],
							[-40.32395, -20.32484],
							[-40.32539, -20.33753],
							[-40.3147, -20.33427],
							[-40.30065, -20.31943],
							[-40.28246, -20.31422],
							[-40.25951, -20.32147],
							[-40.27505, -20.33392],
							[-40.29064, -20.35068],
							[-40.30248, -20.37086],
							[-40.31265, -20.41725],
							[-40.33654, -20.45566],
							[-40.34874, -20.5001],
							[-40.3966, -20.56902],
							[-40.41832, -20.61533],
							[-40.43322, -20.62868],
							[-40.45128, -20.61688],
							[-40.47533, -20.63779],
							[-40.48363, -20.64821],
							[-40.52448, -20.71575],
							[-40.53441, -20.72674],
							[-40.55606, -20.74358],
							[-40.56517, -20.75302],
							[-40.58342, -20.80197],
							[-40.6094, -20.80729],
							[-40.61956, -20.8339],
							[-40.62844, -20.83922],
							[-40.6339, -20.82952],
							[-40.63683, -20.81894],
							[-40.64159, -20.8082],
							[-40.65209, -20.80804],
							[-40.66246, -20.8126],
							[-40.66723, -20.81552],
							[-40.70138, -20.83596],
							[-40.73172, -20.84384],
							[-40.7463, -20.85288],
							[-40.75846, -20.86419],
							[-40.76093, -20.88233],
							[-40.77308, -20.88911],
							[-40.77919, -20.9027],
							[-40.78893, -20.91628],
							[-40.80111, -20.931],
							[-40.80848, -20.96273],
							[-40.80736, -20.99787],
							[-40.81138, -21.01885],
							[-40.81461, -21.03661],
							[-40.83068, -21.04925],
							[-40.83959, -21.06829],
							[-40.84166, -21.07928],
							[-40.84655, -21.0945],
							[-40.92235, -21.19046],
							[-40.95181, -21.2381],
							[-40.96512, -21.27402],
							[-40.96512, -21.27403],
							[-40.97907, -21.26454],
							[-40.98739, -21.25033],
							[-40.9909, -21.24666],
							[-40.99473, -21.24403],
							[-41.04106, -21.22956],
							[-41.0485, -21.22563],
							[-41.06139, -21.21679],
							[-41.06793, -21.21411],
							[-41.10273, -21.21473],
							[-41.17482, -21.22961],
							[-41.22259, -21.22992],
							[-41.2468, -21.23395],
							[-41.25487, -21.2339],
							[-41.26469, -21.23193],
							[-41.29776, -21.21865],
							[-41.30096, -21.21633],
							[-41.30383, -21.21245],
							[-41.30597, -21.20811],
							[-41.3113, -21.20362],
							[-41.32031, -21.20046],
							[-41.36194, -21.19111],
							[-41.38946, -21.18754],
							[-41.39935, -21.18894],
							[-41.40555, -21.19075],
							[-41.42041, -21.20222],
							[-41.42829, -21.20346],
							[-41.43279, -21.20284],
							[-41.43821, -21.20129],
							[-41.45506, -21.19462],
							[-41.46137, -21.19137],
							[-41.4833, -21.17685],
							[-41.49873, -21.17054],
							[-41.50203, -21.17034],
							[-41.50617, -21.17065],
							[-41.50971, -21.17313],
							[-41.5142, -21.17514],
							[-41.51999, -21.17571],
							[-41.53764, -21.17307],
							[-41.54423, -21.17132],
							[-41.55164, -21.16863],
							[-41.55831, -21.16785],
							[-41.56635, -21.16599],
							[-41.57578, -21.16171],
							[-41.59221, -21.15132],
							[-41.60973, -21.14284],
							[-41.62037, -21.13881],
							[-41.64551, -21.1324],
							[-41.65197, -21.12899],
							[-41.67306, -21.11297],
							[-41.67582, -21.11142],
							[-41.68528, -21.10786],
							[-41.69107, -21.10677],
							[-41.69709, -21.10708],
							[-41.70238, -21.10874],
							[-41.70745, -21.11075],
							[-41.7114, -21.11122],
							[-41.71435, -21.10863],
							[-41.71306, -21.10166],
							[-41.71275, -21.0967],
							[-41.71505, -21.09246],
							[-41.72148, -21.08905],
							[-41.72543, -21.08419],
							[-41.7259, -21.07473],
							[-41.72504, -21.06791],
							[-41.7252, -21.06011],
							[-41.72861, -21.04435],
							[-41.72688, -21.03939],
							[-41.7237, -21.03567],
							[-41.72176, -21.03014],
							[-41.72114, -21.02244],
							[-41.71946, -21.01655],
							[-41.71861, -21.0105],
							[-41.71825, -21.00042],
							[-41.71443, -20.98792],
							[-41.71318, -20.98228],
							[-41.71287, -20.97614],
							[-41.71884, -20.95758],
							[-41.72711, -20.93965],
							[-41.72913, -20.92952],
							[-41.72889, -20.92198],
							[-41.7245, -20.91221],
							[-41.72362, -20.9056],
							[-41.72393, -20.88906],
							[-41.72218, -20.88312],
							[-41.71977, -20.87805],
							[-41.71897, -20.87397],
							[-41.72083, -20.86994],
							[-41.73008, -20.86689],
							[-41.73597, -20.86312],
							[-41.74044, -20.8565],
							[-41.74171, -20.85004],
							[-41.73957, -20.83175],
							[-41.7399, -20.82648],
							[-41.74171, -20.82183],
							[-41.74491, -20.81811],
							[-41.74892, -20.81475],
							[-41.75683, -20.81134],
							[-41.8109, -20.79754],
							[-41.86439, -20.77687],
							[-41.87914, -20.76927],
							[-41.88124, -20.76457],
							[-41.88186, -20.75687],
							[-41.87901, -20.75201],
							[-41.87452, -20.74871],
							[-41.86834, -20.74235],
							[-41.86106, -20.73253],
							[-41.84119, -20.68768],
							[-41.83336, -20.67486],
							[-41.81147, -20.64732],
							[-41.80889, -20.63921],
							[-41.80946, -20.63295],
							[-41.813, -20.62923],
							[-41.81801, -20.62716],
							[-41.82359, -20.62654],
							[-41.82904, -20.62753],
							[-41.83785, -20.63326],
							[-41.84258, -20.63543],
							[-41.84788, -20.63554],
							[-41.85315, -20.63228],
							[-41.85377, -20.62778],
							[-41.85225, -20.62303],
							[-41.83984, -20.60675],
							[-41.83403, -20.59626],
							[-41.82044, -20.55632],
							[-41.81778, -20.55058],
							[-41.81388, -20.54655],
							[-41.80302, -20.54086],
							[-41.79752, -20.53637],
							[-41.79597, -20.53079],
							[-41.79693, -20.52541],
							[-41.80566, -20.50603],
							[-41.80737, -20.49937],
							[-41.80775, -20.47332],
							[-41.79631, -20.42692],
							[-41.82987, -20.41178],
							[-41.8346, -20.40728],
							[-41.83992, -20.40124],
							[-41.84522, -20.38718],
							[-41.85163, -20.37591],
							[-41.85462, -20.3678],
							[-41.85586, -20.35834],
							[-41.85473, -20.35209],
							[-41.85269, -20.34651],
							[-41.8502, -20.34186],
							[-41.84085, -20.32966],
							[-41.83336, -20.32284],
							[-41.81607, -20.31132],
							[-41.78284, -20.29421],
							[-41.77695, -20.28812],
							[-41.77091, -20.2784],
							[-41.75551, -20.23525],
							[-41.75318, -20.23044],
							[-41.74708, -20.22233],
							[-41.74308, -20.2182],
							[-41.73778, -20.21391],
							[-41.72858, -20.20926],
							[-41.71592, -20.20771],
							[-41.43496, -20.21215],
							[-41.4055, -20.21293],
							[-41.3939, -20.20068],
							[-41.3761, -20.19494],
							[-41.37026, -20.19122],
							[-41.3662, -20.18678],
							[-41.34334, -20.13107],
							[-41.34197, -20.12533],
							[-41.34111, -20.11919],
							[-41.34109, -20.10606],
							[-41.33406, -20.07557],
							[-41.31119, -20.00901],
							[-41.30902, -19.99857],
							[-41.30871, -19.99552],
							[-41.30895, -19.97397],
							[-41.30771, -19.96069],
							[-41.30499, -19.95361],
							[-41.30132, -19.94865],
							[-41.29244, -19.93935],
							[-41.28223, -19.92602],
							[-41.27799, -19.92173],
							[-41.27373, -19.91873],
							[-41.26853, -19.91687],
							[-41.26257, -19.9163],
							[-41.25621, -19.91687],
							[-41.25011, -19.91796],
							[-41.24262, -19.91646],
							[-41.23409, -19.91191],
							[-41.21497, -19.88979],
							[-41.20818, -19.88395],
							[-41.19257, -19.87605],
							[-41.18813, -19.87078],
							[-41.18528, -19.86509],
							[-41.17709, -19.80933],
							[-41.17725, -19.79755],
							[-41.18079, -19.78634],
							[-41.16479, -19.68696],
							[-41.15684, -19.66045],
							[-41.15038, -19.6526],
							[-41.14642, -19.64934],
							[-41.11273, -19.63089],
							[-41.10645, -19.62495],
							[-41.09733, -19.61441],
							[-41.09167, -19.6032],
							[-41.08563, -19.59922],
							[-41.08038, -19.59849],
							[-41.07472, -19.5986],
							[-41.06984, -19.59705],
							[-41.06589, -19.59379],
							[-41.03697, -19.56273],
							[-41.03183, -19.55415],
							[-41.02963, -19.54708],
							[-41.03121, -19.54217],
							[-41.04656, -19.51535],
							[-41.04806, -19.51054],
							[-41.04896, -19.5048],
							[-41.04824, -19.5],
							[-41.04547, -19.49121],
							[-41.04051, -19.48904],
							[-41.03524, -19.48889],
							[-41.01664, -19.49974],
							[-41.01098, -19.50176],
							[-41.0063, -19.50294],
							[-40.99736, -19.50331],
							[-40.99031, -19.50093],
							[-40.98225, -19.49633],
							[-40.96941, -19.48522],
							[-40.96344, -19.47804],
							[-40.95966, -19.47127],
							[-40.95796, -19.46599],
							[-40.95706, -19.46016],
							[-40.95695, -19.45452],
							[-40.95752, -19.44868],
							[-40.96054, -19.43809],
							[-40.95977, -19.42853],
							[-40.95641, -19.41551],
							[-40.93458, -19.36667],
							[-40.93282, -19.36151],
							[-40.93104, -19.3489],
							[-40.93003, -19.32161],
							[-40.92595, -19.29572],
							[-40.92633, -19.28663],
							[-40.92863, -19.2811],
							[-40.93253, -19.27722],
							[-40.93721, -19.27469],
							[-40.94031, -19.26802],
							[-40.94127, -19.25758],
							[-40.93592, -19.2333],
							[-40.93339, -19.20756],
							[-40.93574, -19.17294],
							[-40.9431, -19.1457],
							[-40.9453, -19.14085],
							[-40.9593, -19.1195],
							[-40.96594, -19.11196],
							[-41.01757, -19.06369],
							[-41.02219, -19.06106],
							[-41.02762, -19.05961],
							[-41.04069, -19.05734],
							[-41.04684, -19.05439],
							[-41.05152, -19.04649],
							[-41.05183, -19.04039],
							[-41.0508, -19.03429],
							[-41.03204, -18.99791],
							[-41.02653, -18.98117],
							[-41.02705, -18.97404],
							[-41.02969, -18.96897],
							[-41.03485, -18.9669],
							[-41.04131, -18.96587],
							[-41.04806, -18.96396],
							[-41.05346, -18.96024],
							[-41.05664, -18.95119],
							[-41.05555, -18.94406],
							[-41.05227, -18.93533],
							[-41.05328, -18.93037],
							[-41.05687, -18.92716],
							[-41.06816, -18.92381],
							[-41.07309, -18.92164],
							[-41.07744, -18.91864],
							[-41.08074, -18.91481],
							[-41.09198, -18.89776],
							[-41.09547, -18.8942],
							[-41.09971, -18.89125],
							[-41.10459, -18.88877],
							[-41.11053, -18.88743],
							[-41.11697, -18.88675],
							[-41.12353, -18.88696],
							[-41.1294, -18.88805],
							[-41.1394, -18.89233],
							[-41.14376, -18.89513],
							[-41.15534, -18.90505],
							[-41.15983, -18.90717],
							[-41.1651, -18.90737],
							[-41.16973, -18.90551],
							[-41.17833, -18.89993],
							[-41.1882, -18.89533],
							[-41.20347, -18.88991],
							[-41.20771, -18.88706],
							[-41.21123, -18.882],
							[-41.22063, -18.86143],
							[-41.23603, -18.85316],
							[-41.23836, -18.84919],
							[-41.23983, -18.84314],
							[-41.23838, -18.83802],
							[-41.23598, -18.83327],
							[-41.23303, -18.82908],
							[-41.22624, -18.82164],
							[-41.2219, -18.81818],
							[-41.21668, -18.81503],
							[-41.20942, -18.81187],
							[-41.19642, -18.80852],
							[-41.17022, -18.80645],
							[-41.14275, -18.80784],
							[-41.12322, -18.80614],
							[-41.11658, -18.8065],
							[-41.11087, -18.808],
							[-41.10699, -18.81115],
							[-41.10513, -18.81637],
							[-41.10413, -18.82221],
							[-41.09927, -18.82655],
							[-41.09082, -18.82939],
							[-40.98212, -18.82614],
							[-40.95915, -18.82273],
							[-40.94406, -18.81653],
							[-40.93949, -18.81379],
							[-40.93189, -18.80738],
							[-40.92794, -18.80278],
							[-40.92421, -18.79699],
							[-40.91985, -18.78743],
							[-40.91791, -18.77989],
							[-40.91695, -18.77239],
							[-40.91675, -18.75958],
							[-40.92693, -18.69338],
							[-40.92871, -18.68806],
							[-40.93106, -18.68346],
							[-40.93401, -18.67938],
							[-40.93739, -18.67566],
							[-40.94132, -18.6725],
							[-40.94615, -18.67002],
							[-40.95222, -18.66873],
							[-41.00336, -18.66708],
							[-41.0139, -18.66491],
							[-41.01894, -18.66284],
							[-41.02274, -18.65958],
							[-41.02591, -18.65555],
							[-41.02759, -18.65028],
							[-41.02847, -18.64444],
							[-41.02868, -18.63824],
							[-41.02142, -18.5892],
							[-41.00958, -18.54042],
							[-41.00726, -18.4953],
							[-41.003, -18.46637],
							[-41.00238, -18.45272],
							[-41.00493, -18.4349],
							[-41.00894, -18.42482],
							[-41.01126, -18.42027],
							[-41.02302, -18.40394],
							[-41.02987, -18.39681],
							[-41.04168, -18.38699],
							[-41.0508, -18.38182],
							[-41.06614, -18.37521],
							[-41.07508, -18.36978],
							[-41.0826, -18.36358],
							[-41.0894, -18.35583],
							[-41.11958, -18.38482],
							[-41.13516, -18.3918],
							[-41.14051, -18.3918],
							[-41.14854, -18.38895],
							[-41.13048, -18.35102],
							[-41.12942, -18.33516],
							[-41.13764, -18.31997],
							[-41.14033, -18.31191],
							[-41.14299, -18.29692],
							[-41.14175, -18.28912],
							[-41.1388, -18.28359],
							[-41.1132, -18.26669],
							[-41.09653, -18.24085],
							[-41.07713, -18.20297],
							[-41.06713, -18.18793],
							[-41.05891, -18.17884],
							[-41.05297, -18.17755],
							[-41.04656, -18.17708],
							[-41.02674, -18.17791],
							[-41.02072, -18.17724],
							[-41.01545, -18.17522],
							[-40.94897, -18.11709],
							[-40.93902, -18.10995],
							[-40.9322, -18.10597],
							[-40.92538, -18.10365],
							[-40.91907, -18.10287],
							[-40.91264, -18.10282],
							[-40.90659, -18.10365],
							[-40.90135, -18.10551],
							[-40.89685, -18.10825],
							[-40.89274, -18.1114],
							[-40.88298, -18.12267],
							[-40.8792, -18.12603],
							[-40.87473, -18.12882],
							[-40.85972, -18.13548],
							[-40.85559, -18.13843],
							[-40.84825, -18.14525],
							[-40.84388, -18.14804],
							[-40.83864, -18.15],
							[-40.83202, -18.15067],
							[-40.80487, -18.15067],
							[-40.79179, -18.153],
							[-40.78435, -18.15331],
							[-40.7735, -18.15067],
							[-40.76926, -18.14556],
							[-40.76722, -18.1391],
							[-40.76722, -18.11905],
							[-40.76947, -18.10763],
							[-40.77151, -18.10256],
							[-40.77422, -18.09776],
							[-40.77725, -18.09357],
							[-40.91106, -17.97177],
							[-40.91442, -17.96702],
							[-40.91621, -17.96154],
							[-40.91478, -17.95208],
							[-40.91075, -17.94867],
							[-40.90579, -17.94826],
							[-40.90127, -17.95069],
							[-40.88988, -17.96061],
							[-40.88548, -17.9634],
							[-40.88019, -17.96541],
							[-40.87401, -17.9664],
							[-40.86737, -17.96655],
							[-40.85481, -17.96485],
							[-40.8382, -17.95973],
							[-40.83239, -17.95875],
							[-40.82621, -17.95906],
							[-40.82099, -17.96076],
							[-40.81644, -17.96345],
							[-40.80823, -17.96945],
							[-40.80301, -17.97146],
							[-40.79743, -17.97301],
							[-40.79179, -17.97353],
							[-40.78657, -17.97244],
							[-40.77404, -17.96479],
							[-40.75841, -17.95973],
							[-40.74335, -17.95053],
							[-40.73423, -17.9464],
							[-40.72622, -17.94423],
							[-40.72004, -17.94485],
							[-40.69214, -17.95301],
							[-40.67973, -17.95534],
							[-40.66619, -17.95647],
							[-40.65418, -17.95286],
							[-40.63868, -17.94593],
							[-40.59377, -17.91849],
							[-40.58292, -17.91358],
							[-40.57049, -17.91162],
							[-40.53233, -17.9001],
							[-40.52594, -17.89963],
							[-40.51956, -17.89999],
							[-40.51383, -17.90149],
							[-40.5092, -17.90397],
							[-40.49086, -17.92102],
							[-40.48236, -17.92655],
							[-40.47765, -17.92862],
							[-40.47254, -17.92971],
							[-40.46626, -17.93002],
							[-40.4582, -17.92841],
							[-40.45342, -17.92521],
							[-40.45065, -17.92056],
							[-40.45016, -17.91467],
							[-40.45334, -17.89762],
							[-40.45349, -17.8911],
							[-40.45179, -17.88402],
							[-40.44652, -17.87643],
							[-40.44107, -17.87426],
							[-40.43665, -17.87555],
							[-40.43399, -17.87974],
							[-40.43014, -17.88981],
							[-40.42719, -17.89395],
							[-40.42308, -17.89684],
							[-40.41781, -17.89886],
							[-40.37208, -17.91115],
							[-40.36725, -17.91358],
							[-40.35895, -17.91932],
						],
					],
				],
				type: "MultiPolygon",
			},
			properties: {
				"ISO3166-1-Alpha-3": "BRA",
				country: "Brazil",
				id: "625",
				name: "Espírito Santo",
			},
			type: "Feature",
		},
	],
};
