.syntax unified
	.align 2, 0
	.global func_0810C754
	.thumb
	.thumb_func
	.type func_0810C754, %function
func_0810C754: @ 0810C754
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldr r5, [r3, #0x7C]
	ldr r1, _0810C798 @ =0xFFFFFF00
	adds r0, r5, r1
	str r0, [r3, #0x7C]
	ldr r4, _0810C79C @ =0x02039B84
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x16
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0810C77C
	ldr r2, _0810C7A0 @ =0xFFFFFE00
	adds r0, r5, r2
	str r0, [r3, #0x7C]
_0810C77C:
	movs r1, #0x12
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	ble _0810C7A4
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x7C]
	ldr r0, [r3, #0x44]
	movs r2, #0x80
	lsls r2, r2, #0x05
	adds r0, r0, r2
	ldr r1, [r1, #0x04]
	cmp r1, r0
	ble _0810C7BA
	b _0810C7B4
_0810C798: .4byte 0xFFFFFF00
_0810C79C: .4byte 0x02039B84
_0810C7A0: .4byte 0xFFFFFE00
_0810C7A4:
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x7C]
	ldr r0, [r3, #0x44]
	ldr r2, _0810C7C0 @ =0xFFFFF000
	adds r0, r0, r2
	ldr r1, [r1, #0x04]
	cmp r1, r0
	bge _0810C7BA
_0810C7B4:
	ldr r0, [r3, #0x7C]
	subs r0, #0x80
	str r0, [r3, #0x7C]
_0810C7BA:
	pop {r4, r5}
	pop {r0}
	bx r0
_0810C7C0: .4byte 0xFFFFF000
.syntax divided
