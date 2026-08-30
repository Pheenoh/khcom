.syntax unified
	.align 2, 0
	.global func_08109ECC
	.thumb
	.thumb_func
	.type func_08109ECC, %function
func_08109ECC: @ 08109ECC
	ldr r2, [r0, #0x2C]
	cmp r2, #0x00
	beq _08109EF0
	movs r3, #0x32
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r2, r0
	ldr r1, _08109EEC @ =0x09EF9C34
	movs r2, #0x20
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	b _08109EF2
_08109EEC: .4byte 0x09EF9C34
_08109EF0:
	ldr r0, _08109EF4 @ =0x09A3DF34
_08109EF2:
	bx lr
_08109EF4: .4byte 0x09A3DF34
.syntax divided
