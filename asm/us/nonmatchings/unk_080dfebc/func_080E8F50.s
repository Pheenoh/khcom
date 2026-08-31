.syntax unified
	.align 2, 0
	.global func_080E8F50
	.thumb
	.thumb_func
	.type func_080E8F50, %function
func_080E8F50: @ 080E8F50
	push {r4, r5, lr}
	add sp, #-0x018
	ldr r5, [sp, #0x024]
	mov r4, sp
	strb r1, [r4, #0x00]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	str r5, [sp, #0x00C]
	mov r1, sp
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	movs r1, #0xDC
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _080E8F82
	bl func_080E8F0C
	mov r2, sp
	mov r1, sp
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r1, #0x14]
	adds r0, r0, r1
	strh r0, [r2, #0x14]
_080E8F82:
	mov r0, sp
	ldrh r0, [r0, #0x14]
	bl CountCardsById
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x62
	bls _080E8F96
	movs r0, #0x00
	b _080E8FA6
_080E8F96:
	ldr r0, _080E8FB0 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0xC8
	ldr r1, _080E8FB4 @ =0x09EF6E64
	mov r2, sp
	bl TaskCreate
	movs r0, #0x01
_080E8FA6:
	add sp, #0x018
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080E8FB0: .4byte 0x02039BA0
_080E8FB4: .4byte 0x09EF6E64
.syntax divided
