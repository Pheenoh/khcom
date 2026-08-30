.syntax unified
	.align 2, 0
	.global func_08103CD8
	.thumb
	.thumb_func
	.type func_08103CD8, %function
func_08103CD8: @ 08103CD8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	movs r5, #0x00
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r7, #0xC0
	lsls r7, r7, #0x12
_08103CEC:
	ldr r0, _08103D4C @ =0x02035B08
	lsls r1, r5, #0x01
	adds r4, r1, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	blt _08103D32
	movs r0, #0x00
	bl func_0800514C
	adds r3, r0, #0x0
	ldr r6, _08103D50 @ =0x09A3ABDC
	movs r0, #0x00
	ldsh r1, [r4, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x19
	lsrs r2, r0, #0x18
	movs r4, #0x00
	cmp r5, r8
	beq _08103D18
	movs r4, #0x03
_08103D18:
	movs r0, #0x00
	str r0, [sp, #0x000]
	lsrs r0, r7, #0x18
	str r0, [sp, #0x004]
	movs r0, #0x06
	str r0, [sp, #0x008]
	movs r0, #0x03
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r3, #0x0
	adds r3, r4, #0x0
	bl func_0800448C
_08103D32:
	movs r1, #0xC0
	lsls r1, r1, #0x12
	adds r7, r7, r1
	adds r5, #0x01
	cmp r5, #0x03
	ble _08103CEC
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08103D4C: .4byte 0x02035B08
_08103D50: .4byte 0x09A3ABDC
.syntax divided
