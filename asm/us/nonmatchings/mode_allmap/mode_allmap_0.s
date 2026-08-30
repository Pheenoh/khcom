.syntax unified
	.align 2, 0
	.global mode_allmap_0
	.thumb
	.thumb_func
	.type mode_allmap_0, %function
mode_allmap_0: @ 080D31C4
	push {r4, r5, r6, lr}
	adds r1, r0, #0x0
	ldr r6, _080D3318 @ =0x02034E81
	movs r0, #0x00
	strb r0, [r6, #0x00]
	cmp r1, #0x01
	bne _080D31D4
	strb r1, [r6, #0x00]
_080D31D4:
	movs r0, #0x00
	movs r1, #0x0E
	bl func_08001F5C
	bl func_080D4D44
	bl func_08004DB0
	movs r0, #0x03
	movs r1, #0x01
	movs r2, #0x1C
	movs r3, #0x08
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x03
	bl func_080055C8
	ldr r1, _080D331C @ =0x097B62B8
	movs r2, #0xF6
	lsls r2, r2, #0x04
	movs r0, #0x03
	bl func_080050B8
	ldr r1, _080D3320 @ =0x09849F78
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r0, #0x03
	bl func_080050DC
	ldr r1, _080D3324 @ =0x0983AD98
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x03
	bl func_0800510C
	movs r0, #0x02
	movs r1, #0x01
	movs r2, #0x1D
	movs r3, #0x08
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x00
	bl func_080055C8
	ldr r1, _080D3328 @ =0x08125E24
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x02
	bl func_0800510C
	bl func_080D30C8
	bl func_080D313C
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1A
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x02
	bl func_080055C8
	ldr r1, _080D332C @ =0x0976B340
	movs r2, #0x90
	lsls r2, r2, #0x06
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D3330 @ =0x0984A0F8
	movs r0, #0x00
	movs r2, #0xE0
	bl func_080050DC
	bl func_080D2F64
	ldr r1, _080D3334 @ =0x0203C4C0
	movs r0, #0x00
	movs r2, #0x02
	movs r3, #0x04
	bl func_0800516C
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1B
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x02
	bl func_080055C8
	ldr r1, _080D3338 @ =0x0203C510
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x04
	bl func_0800516C
	ldr r4, _080D333C @ =0x0203C4F0
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080D3340 @ =0x09EF4E08
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	ldr r0, _080D3344 @ =0x0203C4E0
	movs r5, #0x00
	str r5, [r0, #0x00]
	bl func_080D4EBC
	ldr r4, _080D3348 @ =0x04000208
	strh r5, [r4, #0x00]
	ldr r2, _080D334C @ =0x04000200
	ldrh r0, [r2, #0x00]
	movs r1, #0x04
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080D3350 @ =0x04000004
	ldrh r1, [r2, #0x00]
	movs r0, #0xFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	ldr r3, _080D3354 @ =0x00005020
	adds r1, r3, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _080D3358 @ =0x080D2F21
	bl func_08006C40
	movs r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	beq _080D3300
	ldr r0, _080D335C @ =0x0203DB10
	movs r1, #0xFF
	movs r2, #0x80
	bl func_08120EF8
_080D3300:
	ldr r0, _080D3360 @ =0x0203C534
	movs r1, #0x1E
	strh r1, [r0, #0x00]
	ldr r0, _080D3364 @ =0x0203C508
	strh r1, [r0, #0x00]
	ldr r0, _080D3368 @ =0x02034E38
	strh r5, [r0, #0x00]
	ldr r0, _080D336C @ =0x02034E3A
	strh r5, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D3318: .4byte 0x02034E81
_080D331C: .4byte 0x097B62B8
_080D3320: .4byte 0x09849F78
_080D3324: .4byte 0x0983AD98
_080D3328: .4byte 0x08125E24
_080D332C: .4byte 0x0976B340
_080D3330: .4byte 0x0984A0F8
_080D3334: .4byte 0x0203C4C0
_080D3338: .4byte 0x0203C510
_080D333C: .4byte 0x0203C4F0
_080D3340: .4byte 0x09EF4E08
_080D3344: .4byte 0x0203C4E0
_080D3348: .4byte 0x04000208
_080D334C: .4byte 0x04000200
_080D3350: .4byte 0x04000004
_080D3354: .4byte 0x00005020
_080D3358: .4byte 0x080D2F21
_080D335C: .4byte 0x0203DB10
_080D3360: .4byte 0x0203C534
_080D3364: .4byte 0x0203C508
_080D3368: .4byte 0x02034E38
_080D336C: .4byte 0x02034E3A
.syntax divided
