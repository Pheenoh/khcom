.syntax unified
	.align 2, 0
	.global task_hum_axcel_0
	.thumb
	.thumb_func
	.type task_hum_axcel_0, %function
task_hum_axcel_0: @ 080527B8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r1, _08052860 @ =0x0813F768
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r4, _08052864 @ =0x0813F760
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_0800E314
	movs r2, #0xE2
	lsls r2, r2, #0x01
	adds r1, r5, r2
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_0800E314
	ldr r0, [r5, #0x74]
	ldr r1, [r5, #0x78]
	ldr r2, _08052868 @ =0x04000000
	ldr r3, _0805286C @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x74]
	str r1, [r5, #0x78]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, _08052870 @ =0x0813F5C8
	str r0, [r1, #0x00]
	ldr r1, _08052874 @ =0x00000206
	adds r0, r5, r1
	movs r2, #0x00
	strh r2, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, _08052878 @ =0xFFFFFD00
	str r0, [r1, #0x00]
	movs r1, #0x82
	lsls r1, r1, #0x02
	adds r0, r5, r1
	strh r2, [r0, #0x00]
	movs r0, #0xDE
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldrh r0, [r2, #0x00]
	movs r1, #0x02
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0xFC
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldrh r0, [r2, #0x00]
	orrs r1, r0
	strh r1, [r2, #0x00]
	ldr r0, _0805287C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	movs r2, #0x86
	lsls r2, r2, #0x02
	adds r1, r5, r2
	str r0, [r1, #0x00]
	ldr r0, _08052880 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	movs r2, #0x87
	lsls r2, r2, #0x02
	adds r1, r5, r2
	str r0, [r1, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x02
	adds r0, r5, r1
	movs r1, #0x10
	bl func_08000E64
	pop {r4, r5}
	pop {r0}
	bx r0
_08052860: .4byte 0x0813F768
_08052864: .4byte 0x0813F760
_08052868: .4byte 0x04000000
_0805286C: .4byte 0x00000000
_08052870: .4byte 0x0813F5C8
_08052874: .4byte 0x00000206
_08052878: .4byte 0xFFFFFD00
_0805287C: .4byte 0x08B22BBC
_08052880: .4byte 0x08F69BA4
.syntax divided
