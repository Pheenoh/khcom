.syntax unified
	.align 2, 0
	.global task_bos_jf_map_0
	.thumb
	.thumb_func
	.type task_bos_jf_map_0, %function
task_bos_jf_map_0: @ 080BD8E0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, #0x0
	ldr r0, _080BD980 @ =0x096C5C64
	ldr r1, _080BD984 @ =0x0203ACE0
	movs r2, #0x80
	lsls r2, r2, #0x04
	bl RequestDma3Copy
	ldr r1, _080BD988 @ =0x0203ACD8
	adds r0, r4, #0x0
	adds r0, #0x10
	str r0, [r1, #0x00]
	bl func_080BDAAC
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x04]
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, [r4, #0x08]
	ldrh r2, [r4, #0x0C]
	movs r0, #0x00
	bl LoadBgPalette
	ldr r6, _080BD98C @ =0x02039B84
	ldr r0, [r6, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	ldr r2, _080BD990 @ =0x00023E00
	str r2, [r0, #0x08]
	movs r1, #0x94
	lsls r1, r1, #0x09
	str r1, [r0, #0x0C]
	str r2, [r0, #0x00]
	str r1, [r0, #0x04]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1C]
	str r1, [r0, #0x20]
	movs r5, #0x00
	movs r4, #0x00
	movs r1, #0x0F
	strh r1, [r0, #0x1A]
	strb r5, [r0, #0x18]
	bl func_0802F1C8
	ldr r0, [r6, #0x00]
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	ldr r2, [r0, #0x04]
	lsls r2, r2, #0x08
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	mov r0, r8
	strh r4, [r0, #0x00]
	strh r4, [r0, #0x02]
	ldr r0, _080BD994 @ =0x0203ACD0
	strb r5, [r0, #0x00]
	ldr r0, _080BD998 @ =0x0203B4E0
	strh r4, [r0, #0x00]
	ldr r0, _080BD99C @ =0x0203ACC8
	strh r4, [r0, #0x00]
	ldr r0, _080BD9A0 @ =0x0203ACCC
	strh r4, [r0, #0x00]
	ldr r0, _080BD9A4 @ =0x0203B4E8
	str r4, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BD980: .4byte 0x096C5C64
_080BD984: .4byte 0x0203ACE0
_080BD988: .4byte 0x0203ACD8
_080BD98C: .4byte 0x02039B84
_080BD990: .4byte 0x00023E00
_080BD994: .4byte 0x0203ACD0
_080BD998: .4byte 0x0203B4E0
_080BD99C: .4byte 0x0203ACC8
_080BD9A0: .4byte 0x0203ACCC
_080BD9A4: .4byte 0x0203B4E8
.syntax divided
