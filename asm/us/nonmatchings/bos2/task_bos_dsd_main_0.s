.syntax unified
	.align 2, 0
	.global task_bos_dsd_main_0
	.thumb
	.thumb_func
	.type task_bos_dsd_main_0, %function
task_bos_dsd_main_0: @ 080C217C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	movs r0, #0x74
	adds r0, r0, r7
	mov r10, r0
	str r5, [r7, #0x00]
	movs r0, #0x01
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	ldr r1, [r7, #0x00]
	movs r0, #0xCD
	lsls r0, r0, #0x02
	adds r1, r1, r0
	adds r0, r5, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r1, #0x00
	mov r9, r1
	mov r2, r9
	strb r2, [r7, #0x08]
	mov r0, r9
	strh r0, [r7, #0x06]
	strh r0, [r7, #0x04]
	strh r0, [r7, #0x0A]
	adds r1, r7, #0x0
	adds r1, #0x54
	movs r0, #0x01
	strb r0, [r1, #0x00]
	mov r1, r9
	str r1, [r7, #0x6C]
	ldr r2, _080C2358 @ =0x02039B84
	ldr r0, [r2, #0x00]
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrb r1, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x70
	strb r1, [r0, #0x00]
	ldr r1, _080C235C @ =0x09EF2AA4
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r6, _080C2360 @ =0x096983E4
	movs r2, #0x95
	lsls r2, r2, #0x05
	mov r8, r2
	adds r0, r6, #0x0
	mov r1, r8
	bl func_080026A4
	str r0, [r7, #0x0C]
	adds r4, r7, #0x0
	adds r4, #0x1C
	ldr r1, _080C2364 @ =0x09EF3C34
	ldr r2, _080C2368 @ =0x09EF3C20
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x14]
	adds r0, r6, #0x0
	mov r1, r8
	bl func_080026A4
	str r0, [r7, #0x10]
	adds r4, #0x18
	ldr r1, _080C236C @ =0x09EF3C4C
	ldr r2, _080C2370 @ =0x09EF3C38
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x18]
	ldr r0, _080C2374 @ =0x096FB8C4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x4C]
	ldr r0, _080C2378 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x50]
	movs r0, #0x80
	lsls r0, r0, #0x04
	ldr r1, _080C237C @ =0x096A2F04
	bl func_080028F8
	ldr r1, [r7, #0x00]
	movs r2, #0xD8
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, _080C2380 @ =0x096FB8E4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r7, #0x00]
	movs r2, #0xD9
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, _080C2384 @ =0x096869A4
	movs r1, #0xE8
	lsls r1, r1, #0x03
	bl func_080026A4
	ldr r1, [r7, #0x00]
	movs r2, #0xDA
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, _080C2388 @ =0x096FB864
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r7, #0x00]
	movs r2, #0xDB
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, _080C238C @ =0x096FB884
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r7, #0x00]
	movs r2, #0xDC
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, _080C2390 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	ldr r1, [r7, #0x00]
	movs r2, #0xDD
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, _080C2394 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r7, #0x00]
	movs r2, #0xDE
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	movs r0, #0xDC
	lsls r0, r0, #0x08
	mov r1, r10
	str r0, [r1, #0x04]
	movs r0, #0xB4
	lsls r0, r0, #0x09
	str r0, [r1, #0x08]
	mov r2, r9
	str r2, [r1, #0x0C]
	adds r4, #0x80
	adds r0, r4, #0x0
	movs r1, #0x08
	movs r2, #0x18
	movs r3, #0x64
	bl func_080122AC
	mov r0, r10
	ldr r1, [r0, #0x04]
	ldr r2, [r0, #0x08]
	ldr r3, [r0, #0x0C]
	adds r0, r4, #0x0
	bl func_08012324
	ldr r1, _080C2358 @ =0x02039B84
	ldr r3, [r1, #0x00]
	ldr r1, [r3, #0x00]
	ldr r0, [r5, #0x04]
	subs r1, r1, r0
	asrs r1, r1, #0x08
	adds r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x08
	movs r0, #0x8C
	lsls r0, r0, #0x01
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	adds r0, r7, #0x0
	adds r0, #0x58
	movs r1, #0x0A
	bl func_08000E64
	adds r0, r7, #0x0
	bl func_080C2828
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C2358: .4byte 0x02039B84
_080C235C: .4byte 0x09EF2AA4
_080C2360: .4byte 0x096983E4
_080C2364: .4byte 0x09EF3C34
_080C2368: .4byte 0x09EF3C20
_080C236C: .4byte 0x09EF3C4C
_080C2370: .4byte 0x09EF3C38
_080C2374: .4byte 0x096FB8C4
_080C2378: .4byte 0x08F69BC4
_080C237C: .4byte 0x096A2F04
_080C2380: .4byte 0x096FB8E4
_080C2384: .4byte 0x096869A4
_080C2388: .4byte 0x096FB864
_080C238C: .4byte 0x096FB884
_080C2390: .4byte 0x08B22CE4
_080C2394: .4byte 0x08F69BA4
.syntax divided
