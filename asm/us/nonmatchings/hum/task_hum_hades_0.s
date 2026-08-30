.syntax unified
	.align 2, 0
	.global task_hum_hades_0
	.thumb
	.thumb_func
	.type task_hum_hades_0, %function
task_hum_hades_0: @ 0804E468
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r1, _0804E568 @ =0x0813F324
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r2, _0804E56C @ =0x0813F31C
	adds r0, r7, #0x0
	bl func_0800E314
	ldr r0, [r7, #0x74]
	ldr r1, [r7, #0x78]
	ldr r2, _0804E570 @ =0x00100000
	ldr r3, _0804E574 @ =0x00000000
	orrs r0, r2
	str r0, [r7, #0x74]
	str r1, [r7, #0x78]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r7, r0
	ldr r0, [r2, #0x00]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r2, #0x00]
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r0, #0xE2
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, _0804E578 @ =0xFFFFF600
	str r0, [r1, #0x00]
	movs r0, #0xDE
	lsls r0, r0, #0x01
	adds r2, r7, r0
	ldrh r1, [r2, #0x00]
	movs r0, #0x03
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r4, _0804E57C @ =0x08BAFB62
	movs r0, #0x80
	adds r1, r4, #0x0
	bl func_080028F8
	movs r2, #0xEA
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x02
	adds r1, r4, #0x0
	bl func_080028F8
	movs r2, #0xEC
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r0, #0xE8
	lsls r0, r0, #0x02
	adds r1, r4, #0x0
	bl func_080028F8
	movs r2, #0xEE
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	ldr r0, _0804E580 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	movs r2, #0x8A
	lsls r2, r2, #0x02
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r0, #0xF0
	lsls r0, r0, #0x01
	adds r4, r7, r0
	ldr r5, _0804E584 @ =0x09EE1B78
	ldr r6, _0804E588 @ =0x09EE1B38
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_080059A4
	movs r2, #0xFC
	lsls r2, r2, #0x01
	adds r4, r7, r2
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl func_080059A4
	movs r0, #0x84
	lsls r0, r0, #0x02
	adds r4, r7, r0
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldr r0, _0804E58C @ =0x0813F214
	str r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0804E568: .4byte 0x0813F324
_0804E56C: .4byte 0x0813F31C
_0804E570: .4byte 0x00100000
_0804E574: .4byte 0x00000000
_0804E578: .4byte 0xFFFFF600
_0804E57C: .4byte 0x08BAFB62
_0804E580: .4byte 0x08F69BA4
_0804E584: .4byte 0x09EE1B78
_0804E588: .4byte 0x09EE1B38
_0804E58C: .4byte 0x0813F214
.syntax divided
