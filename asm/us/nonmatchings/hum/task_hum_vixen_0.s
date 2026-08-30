.syntax unified
	.align 2, 0
	.global task_hum_vixen_0
	.thumb
	.thumb_func
	.type task_hum_vixen_0, %function
task_hum_vixen_0: @ 08054440
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r1, _080544B0 @ =0x0813F8C8
	bl func_0800E168
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r4, #0x00
	str r4, [r0, #0x00]
	ldr r0, [r5, #0x74]
	ldr r1, [r5, #0x78]
	ldr r2, _080544B4 @ =0x08000000
	ldr r3, _080544B8 @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x74]
	str r1, [r5, #0x78]
	movs r2, #0xD1
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r4, [r0, #0x00]
	movs r1, #0xD2
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x0F
	bl func_08000E64
	adds r0, r5, #0x0
	bl func_080543B4
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, _080544BC @ =0x0813F7A8
	str r0, [r1, #0x00]
	ldr r0, _080544C0 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080544A8
	movs r0, #0x84
	lsls r0, r0, #0x04
	movs r1, #0x00
	bl func_080028F8
	ldr r1, _080544C4 @ =0x02039B84
	ldr r1, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r1, r1, r2
	str r0, [r1, #0x00]
_080544A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080544B0: .4byte 0x0813F8C8
_080544B4: .4byte 0x08000000
_080544B8: .4byte 0x00000000
_080544BC: .4byte 0x0813F7A8
_080544C0: .4byte 0x02039BB0
_080544C4: .4byte 0x02039B84
.syntax divided
