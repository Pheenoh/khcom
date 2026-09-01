.syntax unified
	.align 2, 0
	.global task_btl_sora_3
	.thumb
	.thumb_func
	.type task_btl_sora_3, %function
task_btl_sora_3: @ 080273B8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x40
	ldr r0, _080273F4 @ =0x0000024E
	bl m4aSongNumStop
	ldr r0, _080273F8 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08027406
	adds r0, r3, #0x0
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08027400
	ldr r0, _080273FC @ =0x02039BB0
	adds r1, r0, #0x0
	adds r1, #0xF8
	ldrh r1, [r1, #0x00]
	strh r1, [r0, #0x32]
	b _08027406
	.byte 0x00, 0x00
_080273F4: .4byte 0x0000024E
_080273F8: .4byte 0x02039B84
_080273FC: .4byte 0x02039BB0
_08027400:
	ldr r1, _08027424 @ =0x02039BB0
	ldrh r0, [r5, #0x2C]
	strh r0, [r1, #0x32]
_08027406:
	adds r0, r5, #0x0
	adds r0, #0x40
	bl func_08012304
	adds r0, r4, #0x0
	bl func_0801DEF4
	adds r0, r4, #0x0
	adds r0, #0x24
	bl TaskPoolDestroy
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08027424: .4byte 0x02039BB0
.syntax divided
