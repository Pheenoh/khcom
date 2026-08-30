.syntax unified
	.align 2, 0
	.global mode_title_2
	.thumb
	.thumb_func
	.type mode_title_2, %function
mode_title_2: @ 080D622C
	push {lr}
	ldr r0, _080D6264 @ =0x02034EA0
	bl func_08000F0C
	ldr r3, _080D6268 @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _080D626C @ =0x04000200
	ldrh r1, [r2, #0x00]
	ldr r0, _080D6270 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080D6274 @ =0x04000004
	ldrh r1, [r2, #0x00]
	ldr r0, _080D6278 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x01
	strh r0, [r3, #0x00]
	bl func_08006C68
	ldr r0, _080D627C @ =0x02034EC4
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D6264: .4byte 0x02034EA0
_080D6268: .4byte 0x04000208
_080D626C: .4byte 0x04000200
_080D6270: .4byte 0x0000FFFB
_080D6274: .4byte 0x04000004
_080D6278: .4byte 0x0000FFDF
_080D627C: .4byte 0x02034EC4
.syntax divided
