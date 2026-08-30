.syntax unified
	.align 2, 0
	.global func_08120460
	.thumb
	.thumb_func
	.type func_08120460, %function
func_08120460: @ 08120460
	push {lr}
	add sp, #-0x004
	ldr r0, _081204C4 @ =0x03007FF0
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x00]
	ldr r3, _081204C8 @ =0x978C92AD
	adds r0, r1, r3
	cmp r0, #0x01
	bhi _081204BE
	adds r0, r1, #0x0
	adds r0, #0x0A
	str r0, [r2, #0x00]
	ldr r1, _081204CC @ =0x04000102
	movs r0, #0x00
	strh r0, [r1, #0x00]
	subs r1, #0x3E
	ldr r0, [r1, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x12
	ands r0, r3
	cmp r0, #0x00
	beq _08120490
	ldr r0, _081204D0 @ =0x84400004
	str r0, [r1, #0x00]
_08120490:
	ldr r1, _081204D4 @ =0x040000D0
	ldr r0, [r1, #0x00]
	ands r0, r3
	cmp r0, #0x00
	beq _0812049E
	ldr r0, _081204D0 @ =0x84400004
	str r0, [r1, #0x00]
_0812049E:
	ldr r0, _081204D8 @ =0x040000C6
	movs r3, #0x80
	lsls r3, r3, #0x03
	adds r1, r3, #0x0
	strh r1, [r0, #0x00]
	adds r0, #0x0C
	strh r1, [r0, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	movs r0, #0xD4
	lsls r0, r0, #0x02
	adds r1, r2, r0
	ldr r2, _081204DC @ =0x05000318
	mov r0, sp
	bl func_08117FE8
_081204BE:
	add sp, #0x004
	pop {r0}
	bx r0
_081204C4: .4byte 0x03007FF0
_081204C8: .4byte 0x978C92AD
_081204CC: .4byte 0x04000102
_081204D0: .4byte 0x84400004
_081204D4: .4byte 0x040000D0
_081204D8: .4byte 0x040000C6
_081204DC: .4byte 0x05000318
.syntax divided
