.syntax unified
	.align 2, 0
	.global func_0810764C
	.thumb
	.thumb_func
	.type func_0810764C, %function
func_0810764C: @ 0810764C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	movs r1, #0x00
	ldr r0, _08107690 @ =0x02035E40
	mov r8, r0
	movs r7, #0x02
_0810765C:
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	lsls r0, r4, #0x01
	add r0, r8
	movs r2, #0x00
	ldsh r5, [r0, r2]
	adds r6, r1, #0x0
	cmp r5, #0x00
	beq _08107698
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	lsls r0, r4, #0x06
	movs r1, #0xA8
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r2, r2, r0
	str r7, [sp, #0x000]
	adds r0, r5, #0x0
	ldr r1, _08107694 @ =0x09A0669C
	movs r3, #0x20
	bl func_08101588
	b _081076B6
	.byte 0x00, 0x00
_08107690: .4byte 0x02035E40
_08107694: .4byte 0x09A0669C
_08107698:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	lsls r0, r4, #0x06
	movs r1, #0xA8
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r2, r2, r0
	str r7, [sp, #0x000]
	movs r0, #0x00
	ldr r1, _081076D0 @ =0x09A0667C
	movs r3, #0x20
	bl func_08101588
_081076B6:
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r6, r2
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _0810765C
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_081076D0: .4byte 0x09A0667C
.syntax divided
