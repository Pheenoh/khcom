.syntax unified
	.align 2, 0
	.global func_080B18C4
	.thumb
	.thumb_func
	.type func_080B18C4, %function
func_080B18C4: @ 080B18C4
	push {r4, r5, lr}
	ldr r1, _080B1944 @ =0x096F8C64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl LoadBgMap
	movs r5, #0xC8
	lsls r5, r5, #0x04
	ldr r1, _080B1948 @ =0x088B6560
	adds r0, r5, #0x0
	bl AllocObjTiles
	ldr r4, _080B194C @ =0x02034B44
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x08]
	ldr r0, _080B1950 @ =0x09EDE8CC
	ldr r0, [r0, #0x48]
	str r0, [r1, #0x18]
	ldr r1, _080B1954 @ =0x091CF5D4
	adds r0, r5, #0x0
	bl AllocObjTiles
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x0C]
	ldr r0, _080B1958 @ =0x09EEE4C8
	ldr r0, [r0, #0x18]
	str r0, [r1, #0x1C]
	ldr r0, _080B195C @ =0x0962CAFC
	movs r1, #0xD0
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x28]
	ldr r0, _080B1960 @ =0x096FBDE4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x30]
	ldr r0, _080B1964 @ =0x09EF38DC
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x38]
	ldr r0, _080B1968 @ =0x0962D196
	movs r1, #0xC0
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x2C]
	ldr r0, _080B196C @ =0x096FBE04
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x34]
	ldr r0, _080B1970 @ =0x09EF38E4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x3C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B1944: .4byte 0x096F8C64
_080B1948: .4byte 0x088B6560
_080B194C: .4byte 0x02034B44
_080B1950: .4byte 0x09EDE8CC
_080B1954: .4byte 0x091CF5D4
_080B1958: .4byte 0x09EEE4C8
_080B195C: .4byte 0x0962CAFC
_080B1960: .4byte 0x096FBDE4
_080B1964: .4byte 0x09EF38DC
_080B1968: .4byte 0x0962D196
_080B196C: .4byte 0x096FBE04
_080B1970: .4byte 0x09EF38E4
.syntax divided
