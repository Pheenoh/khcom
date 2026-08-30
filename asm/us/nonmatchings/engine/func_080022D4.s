.syntax unified
	.align 2, 0
	.global func_080022D4
	.thumb
	.thumb_func
	.type func_080022D4, %function
func_080022D4: @ 080022D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r2, #0x0
	mov r12, r3
	ldr r2, [sp, #0x01C]
	ldr r3, [sp, #0x020]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	mov r0, r12
	cmp r0, #0x00
	beq _08002300
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	bne _08002304
_08002300:
	movs r0, #0x00
	b _080023B2
_08002304:
	ldr r0, _080023BC @ =0x030074C8
	ldr r3, [r0, #0x00]
	ldr r1, _080023C0 @ =0x000028A8
	adds r4, r3, r1
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _080023C4 @ =0x00001AB8
	adds r0, r0, r1
	strh r5, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _080023C8 @ =0x00001ABA
	adds r0, r0, r1
	strh r7, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r5, _080023CC @ =0x00001AA8
	adds r0, r3, r5
	adds r0, r0, r1
	str r6, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r7, _080023D0 @ =0x00001AAC
	adds r0, r3, r7
	adds r0, r0, r1
	mov r1, r12
	str r1, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r7, #0x04
	adds r1, r3, r7
	adds r1, r1, r0
	ldr r0, [sp, #0x018]
	str r0, [r1, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _080023D4 @ =0x00001ABE
	adds r0, r0, r1
	strh r2, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r2, _080023D8 @ =0x00001ABC
	adds r0, r0, r2
	mov r7, r8
	strh r7, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	subs r2, #0x08
	adds r1, r3, r2
	adds r1, r1, r0
	ldr r0, [r6, #0x20]
	str r0, [r1, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x02
	ldr r6, _080023DC @ =0x000026A8
	adds r2, r3, r6
	adds r2, r2, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r5
	adds r3, r3, r0
	str r3, [r2, #0x00]
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x01
_080023B2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080023BC: .4byte 0x030074C8
_080023C0: .4byte 0x000028A8
_080023C4: .4byte 0x00001AB8
_080023C8: .4byte 0x00001ABA
_080023CC: .4byte 0x00001AA8
_080023D0: .4byte 0x00001AAC
_080023D4: .4byte 0x00001ABE
_080023D8: .4byte 0x00001ABC
_080023DC: .4byte 0x000026A8
.syntax divided
