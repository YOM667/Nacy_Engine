#version 330 core
#define NUM_OCTAVES 16

uniform float alpha;
uniform float iTime;
uniform vec2 iResolution;

mat3 rotX(float a) {
    float c = cos(a);
    float s = sin(a);
    return mat3(
    1, 0, 0,
    0, c, -s,
    0, s, c
    );
}
mat3 rotY(float a) {
    float c = cos(a);
    float s = sin(a);
    return mat3(
    c, 0, -s,
    0, 1, 0,
    s, 0, c
    );
}

float random(vec2 pos) {
    return fract(sin(dot(pos.xy, vec2(1399.9898, 78.233))) * 43758.5453123);
}

float noise(vec2 pos) {
    vec2 i = floor(pos);
    vec2 f = fract(pos);
    float a = random(i + vec2(0.0, 0.0));
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
    vec2 u = f * f * (3.0 - 2.0 * f);
    return mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}

float fbm(vec2 pos) {
    float v = 0.0;
    float a = 0.5;
    vec2 shift = vec2(100.0);
    mat2 rot = mat2(cos(0.5), sin(0.5), -sin(0.5), cos(0.5));
    for (int i=0; i<NUM_OCTAVES; i++) {
        v += a * noise(pos);
        pos = rot * pos * 2.0 + shift;
        a *= 0.5;
    }
    return v;
}

void main(void) {
    vec2 p = (gl_FragCoord.xy * 1.0 - iResolution.xy) / min(iResolution.x, iResolution.y);

    float t = 0.0, d;

    float time2 = 0.6 * iTime / 2.0;

    vec2 q = vec2(0.0);
    q.x = fbm(p + 0.30 * time2);
    q.y = fbm(p + vec2(1.0));
    vec2 r = vec2(0.0);
    r.x = fbm(p + 1.0 * q + vec2(1.2, 3.2) + 0.135 * time2);
    r.y = fbm(p + 1.0 * q + vec2(8.8, 2.8) + 0.126 * time2);
    float f = fbm(p + r);
    vec3 color = mix(
    vec3(0.0, 0.0, 0),
    vec3(1, 0, 0.7),
    clamp((f * f) * 8.0, 0.0, 5.0)
    );

    color = mix(
    color,
    vec3(0, 0, 1),
    clamp(length(q), 0.0, 1.0)
    );


    color = mix(
    color,
    vec3(1, 1, 1),
    clamp(length(r.x), 0.0, 1.0)
    );

    color = (f * f * f + 0.2 * f * f + 0.4 * f) * color;

    gl_FragColor = vec4(color, alpha);
}


/*#version 330 core

uniform vec2 iResolution;
uniform float iTime;
uniform float alpha;
out vec4 fragColor;

void main()
{
    float aspect_ratio = iResolution.y / iResolution.x;

	vec2 uv = gl_FragCoord.xy / iResolution.x;

    uv -= vec2(0.5, 0.5 * aspect_ratio);

    float rot = radians(-30. -iTime); // radians(45.0*sin(iTime));

    mat2 rotation_matrix = mat2(cos(rot), -sin(rot), sin(rot), cos(rot));

   	uv = rotation_matrix * uv;

    vec2 scaled_uv = 20.0 * uv;

    vec2 tile = fract(scaled_uv);

    float tile_dist = min(min(tile.x, 1.0-tile.x), min(tile.y, 1.0-tile.y));

    float square_dist = length(floor(scaled_uv));
    
    float edge = sin(iTime-square_dist*20.);
    edge = mod(edge * edge, edge / edge);

    float value = mix(tile_dist, 1.0-tile_dist, step(1.0, edge));

    edge = pow(abs(1.0-edge), 2.2) * 0.5;

    value = smoothstep(edge-0.05, edge, 0.95*value);
    
    value += square_dist*.1;

    value *= 0.8 - 0.3;

    fragColor = vec4(pow(value, 2.), pow(value, 1.5), pow(value, 1.2), alpha);
}*/