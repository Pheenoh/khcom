.syntax unified
	.align 2, 0
	.global task_bos_jf_majin_0
	.thumb
	.thumb_func
	.type task_bos_jf_majin_0, %function
task_bos_jf_majin_0: @ 080BE508
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	str r5, [r7, #0x00]
	ldr r4, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r0, #0x48
	movs r6, #0x00
	strb r6, [r0, #0x00]
	subs r0, #0x02
	movs r1, #0x00
	mov r8, r1
	strh r6, [r0, #0x00]
	subs r0, #0x02
	strh r6, [r0, #0x00]
	str r4, [r7, #0x50]
	str r3, [r7, #0x54]
	str r2, [r7, #0x58]
	adds r0, #0x18
	strh r6, [r0, #0x00]
	ldr r0, _080BE660 @ =0x0203ACC4
	ldrh r3, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x5E
	strh r3, [r0, #0x00]
	ldr r0, _080BE664 @ =0x0203ACD4
	ldrh r2, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x60
	strh r2, [r0, #0x00]
	ldr r0, _080BE668 @ =0x0203ACC0
	ldrh r1, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x62
	strh r1, [r0, #0x00]
	adds r0, #0x02
	strh r3, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r1, [r0, #0x00]
	subs r0, #0x1F
	mov r1, r8
	strb r1, [r0, #0x00]
	adds r0, #0x01
	strh r6, [r0, #0x00]
	ldr r0, _080BE66C @ =0x00000133
	str r0, [r7, #0x4C]
	adds r0, r7, #0x0
	adds r0, #0x6A
	strb r1, [r0, #0x00]
	ldr r4, _080BE670 @ =0x0203B4F0
	ldr r0, _080BE674 @ =0x08125E24
	str r0, [r4, #0x00]
	str r0, [r4, #0x04]
	str r0, [r4, #0x08]
	ldr r1, _080BE678 @ =0x0203B510
	str r1, [r4, #0x0C]
	ldr r0, _080BE67C @ =0x096CAC64
	movs r2, #0x80
	lsls r2, r2, #0x04
	bl func_080043B4
	ldr r0, _080BE680 @ =0x0203B500
	mov r8, r0
	str r4, [r0, #0x00]
	ldr r1, _080BE684 @ =0x096FB584
	movs r0, #0x01
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _080BE688 @ =0x09665C04
	movs r2, #0x9C
	lsls r2, r2, #0x06
	movs r0, #0x01
	bl func_080050B8
	mov r0, r8
	ldr r1, [r0, #0x00]
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r0, _080BE68C @ =0x09682AA4
	movs r1, #0xA0
	lsls r1, r1, #0x06
	bl func_080026A4
	str r0, [r7, #0x04]
	ldr r0, _080BE690 @ =0x096FB5A4
	movs r1, #0x60
	bl func_08002A14
	str r0, [r7, #0x08]
	ldr r0, _080BE694 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x0C]
	adds r1, r7, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _080BE698 @ =0x0002A200
	str r0, [r7, #0x30]
	movs r0, #0x93
	lsls r0, r0, #0x09
	str r0, [r7, #0x34]
	adds r0, r7, #0x0
	adds r0, #0x40
	strh r6, [r0, #0x00]
	strh r6, [r7, #0x3C]
	adds r4, r7, #0x0
	adds r4, #0x14
	ldr r1, _080BE69C @ =0x09EF3B40
	ldr r2, _080BE6A0 @ =0x09EF3A48
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x10]
	ldr r0, _080BE6A4 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r1, [r3, #0x00]
	ldr r0, [r5, #0x04]
	subs r1, r1, r0
	asrs r1, r1, #0x08
	movs r0, #0xC2
	lsls r0, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x08
	movs r0, #0x93
	lsls r0, r0, #0x01
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	adds r4, #0x58
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_08000E64
	ldr r1, _080BE6A8 @ =0x09EF2A74
	ldr r2, [r7, #0x00]
	adds r0, r4, #0x0
	bl func_08000E14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080BE660: .4byte 0x0203ACC4
_080BE664: .4byte 0x0203ACD4
_080BE668: .4byte 0x0203ACC0
_080BE66C: .4byte 0x00000133
_080BE670: .4byte 0x0203B4F0
_080BE674: .4byte 0x08125E24
_080BE678: .4byte 0x0203B510
_080BE67C: .4byte 0x096CAC64
_080BE680: .4byte 0x0203B500
_080BE684: .4byte 0x096FB584
_080BE688: .4byte 0x09665C04
_080BE68C: .4byte 0x09682AA4
_080BE690: .4byte 0x096FB5A4
_080BE694: .4byte 0x08F69BC4
_080BE698: .4byte 0x0002A200
_080BE69C: .4byte 0x09EF3B40
_080BE6A0: .4byte 0x09EF3A48
_080BE6A4: .4byte 0x02039B84
_080BE6A8: .4byte 0x09EF2A74
.syntax divided
