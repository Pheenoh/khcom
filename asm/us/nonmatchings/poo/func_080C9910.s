.syntax unified
	.align 2, 0
	.global func_080C9910
	.thumb
	.thumb_func
	.type func_080C9910, %function
func_080C9910: @ 080C9910
	push {r4, lr}
	add sp, #-0x008
	ldr r0, _080C9958 @ =0x0203C3EC
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080C995C @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	ldr r1, [r2, #0x04]
	asrs r1, r1, #0x08
	ldr r2, [r2, #0x08]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080C9960 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, _080C9964 @ =0x096FC010
	movs r4, #0x06
	ldsh r2, [r3, r4]
	movs r4, #0x08
	ldsh r3, [r3, r4]
	str r3, [sp, #0x000]
	str r3, [sp, #0x004]
	movs r3, #0x00
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080C9968
	movs r0, #0x00
	b _080C996A
_080C9958: .4byte 0x0203C3EC
_080C995C: .4byte 0x0203C40C
_080C9960: .4byte 0x0203C3F8
_080C9964: .4byte 0x096FC010
_080C9968:
	movs r0, #0x01
_080C996A:
	add sp, #0x008
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
