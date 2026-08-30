.syntax unified
	.align 2, 0
	.global func_080DABFC
	.thumb
	.thumb_func
	.type func_080DABFC, %function
func_080DABFC: @ 080DABFC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r6, #0x00
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0x80
	subs r0, r0, r2
	lsls r1, r0, #0x08
	ldr r0, [r4, #0x00]
	cmp r0, r1
	bge _080DAC1C
	str r1, [r4, #0x00]
	movs r6, #0x01
_080DAC1C:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r2, r1
	lsls r2, r0, #0x08
	ldr r0, [r4, #0x00]
	cmp r0, r2
	ble _080DAC2E
	str r2, [r4, #0x00]
	movs r6, #0x01
_080DAC2E:
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	movs r0, #0x90
	lsls r0, r0, #0x02
	subs r0, r0, r3
	lsls r2, r0, #0x08
	ldr r0, [r5, #0x00]
	cmp r0, r2
	bge _080DAC44
	str r2, [r5, #0x00]
	movs r6, #0x01
_080DAC44:
	movs r0, #0x9E
	lsls r0, r0, #0x02
	subs r0, r0, r3
	lsls r3, r0, #0x08
	ldr r0, [r5, #0x00]
	cmp r0, r3
	ble _080DAC56
	str r3, [r5, #0x00]
	movs r6, #0x01
_080DAC56:
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
